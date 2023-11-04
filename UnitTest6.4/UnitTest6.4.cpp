#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-6.4.it/PR-6.4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int* arr = new int[7];
			arr[0] = -2;
			arr[1] = 0;
			arr[2] = 5;
			arr[3] = -3;
			arr[4] = 1;
			arr[5] = 0;
			arr[6] = 10;

			int sum = Sum(7, arr);

			Assert::AreEqual(sum, 3);

			int product = Product(7, arr);
			Assert::AreEqual(product, -100);

			Transform(7, arr);
			int arr2[] = { 0, 5, 1, 0, 10, -2, -3 };
			for (int i = 0; i < 7; i++) {
				Assert::AreEqual(arr[i], arr2[i]);
			}

			delete[] arr;
		}
	};
}
