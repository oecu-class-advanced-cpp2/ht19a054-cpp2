#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
/* --------------------------------------------------------------- */
/*
*  is_prime
*
*
�^����ꂽ������ x�ɑ΂��đf�����ǂ������肷��
*/
/* -------------------------------------------------------------- */
bool is_prime(int x) {
	//x��2����x-1�܂ł̐��Ŋ���邩���`�F�b�N����
	//���������ꂽ��false��Ԃ�
	if (x == 1)
		return false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return false;
	};
	return true;
}
/* --------------------------------------------------------------- */
/*
*  nth_prime
*
*
�^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
*  �f����Ԃ��B
*
*  TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
*  �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */
int nth_prime(int a, int d, int n) {
	int num = a;
	int count = 0; //�f���Ȃ瑝��
	while (num<1000000) {
		if (is_prime(num))
			count++;
		if (count == n) {
			break;
			cout << 0;
		}
		num = num + d;
	};
	return num;
}
/* --------------------------------------------------------------- */
/*
*  comparison_prime
*
*
�^����ꂽ������ y�Ƃ� �����������ׂ�
*/
/* -------------------------------------------------------------- */
int comparison_prime(int y, int z) {
	if (y == z)
		return printf("%d�̒l�Ő�����\n", z);
	return printf("%d�̒l�͊ԈႢ�ŁA������%d\n", z, y);
}

int main() {

	comparison_prime(nth_prime(367, 186, 151), 92809);
	comparison_prime(nth_prime(179, 10, 203), 6709);
	comparison_prime(nth_prime(271, 37, 39), 12037);
	comparison_prime(nth_prime(103, 230, 1), 103);
	comparison_prime(nth_prime(27, 104, 185), 93523);
	comparison_prime(nth_prime(253, 50, 85), 14503);
	comparison_prime(nth_prime(1, 1, 1), 2);
	comparison_prime(nth_prime(9075, 337, 210), 899429);
	comparison_prime(nth_prime(307, 24, 79), 5107);
	comparison_prime(nth_prime(331, 221, 177), 412717);
	comparison_prime(nth_prime(259, 170, 40), 22699);
	comparison_prime(nth_prime(269, 58, 102), 25673);
    
    comparison_prime(nth_prime(1, 1, 1), 3);
	cin.get();
	return 0;
}