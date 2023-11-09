#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rek
{
	TEST_CLASS(UnitTest71rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			srand((unsigned)time(NULL));
			int Low = 1;
			int High = 1;
			int rowCount = 8;
			int colCount = 6;

			int** a = new int* [rowCount];

			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, Low, High);

			int S = 0;
			int k = 0;

			Calc(a, rowCount, colCount, S, k);

			Assert::AreEqual(S, 48);

		}
	};
}
