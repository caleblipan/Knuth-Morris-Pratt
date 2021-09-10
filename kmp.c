#include <stdio.h>

int kmp(char str1[], size_t n, char str2[], size_t m) {
	int piTable[n + 1];
	piTable[0] = 0;

	// Assume everyone is 0 at first
	for (int i = 1; i < n + 1; i++)
		piTable[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str1[j] == str1[i]) {
				piTable[j + 1] = i + 1;
				break;
			}
		}
	}

	// Comparison
	int startingPosition = -1;
	int i, j; 
	i = j = 0;

	while (i < m && j < n) {
		if (str2[i] == str1[j])	{
			i++;
			j++;
		} else {
			if (j == 0)
				i++;
			else
				j = piTable[j];
		}
	}
	if (j == n) startingPosition = i - n;

	return startingPosition;
}

int main() {
	char str1[] = "ababd";
	size_t n = sizeof(str1)/sizeof(str1[0]) - 1;
	char str2[] = "ababcababdababc";
	size_t m = sizeof(str2)/sizeof(str2[0]) - 1;
	
	printf("Starting index: %d", kmp(str1, n, str2, m));

	return 0;
}
