// ExFunc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Funcs.h"

int main()
{


	while (true) {


		cout << "\n\nѡ�����:\n1 ����Token\n2 ����License\n3 ��֤License\n  " << endl;
		int op;
		cin >> op;

		switch (op) {
		case 1:
		{
			bool success = genToken(tokenFilename, logFilename);
			if (success) {
				cout << "\n����"<< tokenFilename<<" ��";
			}
			else
			{
				cout << "\nʧ�ܣ�";
			}
		}

		break;
		case 2: {
			bool success = genLicnese(tokenFilename, licenseFilename, logFilename);
			if (success) {
				cout << "\n����"<< licenseFilename <<" ��";
			}
			else
			{
				cout << "\nʧ�ܣ�";
			}
		}

				break;

		case 3: {
			bool success = verifyLicense(licenseFilename,logFilename);
			if (success) {
				cout << "\n��֤�ɹ���";
			}
			else
			{
				cout << "\n��֤ʧ�ܣ�";
			}
		}

				break;
		}
	}

    return 0;
}

