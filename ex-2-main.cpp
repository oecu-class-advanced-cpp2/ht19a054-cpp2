#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi
		�w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
		�ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B
		1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
		�������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
		����܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int num = 1;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (int(*pos) >= 50 && 57 >= int(*pos)) {
					if (num > 1) {
						std::cout << *pos << ":mcxi�L�@�ł͐����͘A�����܂���" << std::endl;
					}
					else {
						num = int(*pos) - 48;
					}
				}
				else {
					switch (int(*pos)) {
					case 109:
						if (value_ == 0) {
							num *= 1000;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi�L�@�̉p����mcxi�̏��ɋL�ڂ��܂�" << std::endl;
						}
						break;
					case 99:
						if (value_ % 1000 == 0) {
							num *= 100;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi�L�@�̉p����mcxi�̏��ɋL�ڂ��܂�" << std::endl;
						}
						break;
					case 120:
						if (value_ % 100 == 0) {
							num *= 10;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi�L�@�̉p����mcxi�̏��ɋL�ڂ��܂�" << std::endl;
						}
						break;
					case 105:
						if (value_ % 10 == 0) {
							num *= 1;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi�L�@�̉p����mcxi�̏��ɋL�ڂ��܂�" << std::endl;
						}
						break;
					default:
						std::cout << *pos << ":mcxi�L�@�� " << *pos << " �͊܂܂�܂���" << std::endl;
					}
				}
			}
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+
		2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
		*/
		/* ----------------------------------------------------------------- */
		//+�L�����I�[�o�[���[�h
		mcxi operator+(const mcxi& rhs) {
			mcxi tc("");
			tc.value_ = this->value_ + rhs.value_;
			return tc;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string
		���݂̒l�� mcxi �L�@�ɕϊ����܂��B
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string(std::string x) const {
			std::string str;
			std::string seikai = "�͐���";
			std::string huseikai = "�͕s�����A������";
			std::string a = x;
			std::string kotae;
			if (value_ / 1000 >= 2) {
				str += (value_ / 1000) + 48;
			}
			if (value_ / 1000 >= 1) {
				str += 'm';
			}
			if ((value_ % 1000) / 100 >= 2) {
				str += ((value_ % 1000) / 100) + 48;
			}
			if ((value_ % 1000) / 100 >= 1) {
				str += 'c';
			}
			if ((value_ % 100) / 10 >= 2) {
				str += ((value_ % 100) / 10) + 48;
			}
			if ((value_ % 100) / 10 >= 1) {
				str += 'x';
			}
			if ((value_ % 10) >= 2) {
				str += (value_ % 10) + 48;
			}
			if ((value_ % 10) >= 1) {
				str += 'i';
			}
			if (x == str) {
				kotae = x + seikai;
				return kotae;
			}
			else {
				kotae = x + huseikai + str;
				return kotae;
			}
		}
	};
}

int main() {

	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string("3x") << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string("x") << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string("6cx") << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string("5m9c9x9i") << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string("m") << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string("9m9c9x9i") << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string("mi") << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string("mi") << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string("mx") << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string("9m9c9x9i") << std::endl;

	cpp2::mcxi a10("9m8c7xi");
	cpp2::mcxi b10("c2x8i");
	auto result10 = a10 + b10;
	std::cout << "x" << " " << result10.to_string("x") << std::endl;
}