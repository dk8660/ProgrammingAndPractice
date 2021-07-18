#include <stdio.h>
int main() {
	int n;
	int a[10000] = {0};
	int b[10000] = {0};
	int c[10000] = {0};
	int count[10000] = {0};
	int tmp = 0;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	int j = 0;
	for(int i=0;i<n;i++) {
		if(b[j] != c[i] && c[i] != 0) {
			b[j] = c[i];
			for(int k=0;k<n;k++) {
				if(b[j] == c[k])
					c[k] = 0;
			}
			j++;
		}
	}
	int m = j;
	/*for(j=0;j<m;j++) {
		printf("%d\n",b[j]);
	}*/
	for (j=0;j<m;j++) {
		for (int i=0;i<n;i++) {
			if(b[j] == a[i])
				count[j]++;
		}
	}
	for(j=0;j<m;j++) {
		if(count[j] >= tmp)
			tmp = count[j];
	}
	int d[10000] = {0};
	int l = 0;
	for(j=0;j<m;j++) {
		if(tmp == count[j]) {
			d[l] = b[j];
			l++;
		}
	}
	int o = l;
	int tmp_number = 0;
	for(int k=0;k<o;k++) {
		if(d[k] > tmp_number)
			tmp_number = d[k];
	}	
	printf("%d %d\n",tmp_number, tmp);
	return 0;
}
