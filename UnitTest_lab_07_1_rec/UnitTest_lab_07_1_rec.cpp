#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07_1_rec/lab_07_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab071rec
{
	TEST_CLASS(UnitTestlab071rec)
	{
	public:
		
		TEST_METHOD(TestNeedSwap)
		{
			const int rowCount = 2;
			const int colCount = 4;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 20; a[0][1] = 5; a[0][2] = 0; a[0][3] = 10;
			a[1][0] = 10; a[1][1] = 5; a[1][2] = 0; a[1][3] = 10;

			Assert::IsTrue(NeedSwap(a, 0));

			a[0][0] = 10; a[0][1] = 5; a[0][2] = 0; a[0][3] = 10;
			a[1][0] = 20; a[1][1] = 5; a[1][2] = 0; a[1][3] = 10;

			Assert::IsFalse(NeedSwap(a, 0));

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestCalcRows)
		{
			const int rowCount = 2;
			const int colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 12;
			a[0][1] = 12;
			a[1][0] = 18;
			a[1][1] = 7;

			int S = 0;
			int k = 0;

			CalcRows(a, rowCount, colCount, 0, S, k);

			Assert::AreEqual(30, S);
			Assert::AreEqual(2, k);
			Assert::AreEqual(12, a[0][0]);
			Assert::AreEqual(0, a[0][1]);
			Assert::AreEqual(0, a[1][0]);
			Assert::AreEqual(7, a[1][1]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestChange)
		{
			const int rowCount = 2;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;

			Change(a, 0, 1, colCount, 0);

			Assert::AreEqual(4, a[0][0]);
			Assert::AreEqual(5, a[0][1]);
			Assert::AreEqual(6, a[0][2]);
			Assert::AreEqual(1, a[1][0]);
			Assert::AreEqual(2, a[1][1]);
			Assert::AreEqual(3, a[1][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
