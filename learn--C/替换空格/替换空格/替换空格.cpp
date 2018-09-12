#include <cstdio>
#include <cstdlib>
#include <cstring>

int replaceSpace(char *mystr) {
	int ret = 0;
	if (mystr == NULL) {
		ret = -1;
		printf("error: *mystr == NULL");
		return ret;
	}
	//1.空格数
	int length = 0;
	int length_space = 0;
	while (mystr[length] != '\0') {
		if (mystr[length++] == ' ')
			length_space++;
	}
	//2.计算空格替换成"%20"后的字符串长度
	int original_len = length;
	int new_len = length + 2 * length_space;

	//空格替换成"%20"
	while (original_len >= 0 && new_len > original_len) {
		if (mystr[original_len] == ' ') {
			mystr[new_len--] = '0';
			mystr[new_len--] = '2';
			mystr[new_len--] = '%';
			original_len--;
		}
		else {
			mystr[new_len--] = mystr[original_len--];
		}
	}
	return ret;
}

int main()
{
	int ret = 0;
	char str[1024] = "my name is ";

	ret = replaceSpace(str);

	if (ret != 0) {
		printf("func replaceSpace is erro:%d", ret);
		return ret;
	}
	printf("The replaced String: %s", str);

	return ret;
	
}