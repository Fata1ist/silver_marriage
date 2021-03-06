string s;
int len;
cin >> s;
len = s.size();

...

//prefix-function

	vector<int> p;
	p.push_back(0);
	for (int i = 1; i < len; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) j++;
		p.push_back(j);
	}

//z-function

	vector<int> z;
	z.push_back(0);
	int l = 0, r = 0;
	for (int i = 1; i < len; i++)
		if (i > r) {
			int j = 0;
			while (j < len && s[j] == s[i + j]) j++;
			z.push_back(j);
			l = i;
			r = i + j - 1;
		} else
			if (z[i - l] < r - i + 1)
				z.push_back(z[i - l]);
			else {
				int j = 0;
				while (r + j < len && s[r + j] == s[r - i + j]) j++;
				z.push_back(r - i + j);
				l = i;
				r = r + j - 1;
			}

//hash-function

	const int ppow = (int)31;

	vector<int64> p, hash;
	p.push_back(1);
	hash.push_back(s[0] - 'a' + 1);
	for (int i = 1; i < len; i++) {
		p.push_back(p[i - 1] * ppow);
		hash.push_back(hash[i - 1] * ppow + (s[i] - 'a' + 1));
	}