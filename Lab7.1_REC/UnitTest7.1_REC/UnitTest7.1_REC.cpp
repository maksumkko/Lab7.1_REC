#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1_REC/Lab7.1_REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71REC
{
	TEST_CLASS(UnitTest71REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 10; a[0][1] = -3; a[0][2] = 25;
            a[1][0] = 7;  a[1][1] = -5; a[1][2] = 0;
            a[2][0] = 15; a[2][1] = 20; a[2][2] = -42;

            int S = 0;
            int k = 0;

            Calc(a, rowCount, colCount, S, k, 0, 0);

            Assert::AreEqual(S, -43);
            Assert::AreEqual(k, 5);

            Assert::AreEqual(a[0][1], 0);
            Assert::AreEqual(a[1][1], 0);
            Assert::AreEqual(a[1][2], 0);
            Assert::AreEqual(a[2][2], 0);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
