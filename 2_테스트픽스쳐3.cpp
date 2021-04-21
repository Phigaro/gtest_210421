// 2_테스트픽스쳐.cpp
class Calculator {
public:
	// Calculator(int n) {}

	double Display() { return 0; }
	
	void Enter(double v) { }
	void PressPlus() {}
	void PressMinus() {}
	void PressEquals() {}
};

//-------------------
#include <gtest/gtest.h>
#define SPEC printf

// 픽스쳐 설치하는 방법.
//  3. 암묵적 설치(Implicit SetUp)
//   : 여러 테스트에서 같은 테스트 픽스쳐의 코드를 SetUp() 함수에서 생성한다.
//   => xUnit Test Framework 기능
//   장점: 테스트 코드 중복을 제거하고, 꼭 필요하지 않은 상호작용을 캡슐화 수 있다.
//   단점: 픽스쳐 설치 코드가 테스트 함수 밖에 존재하기 때문에,
//         테스트 함수만으로 테스트 코드를 이해가 어려울 수 있다.

class CalculatorTest : public testing::Test {
protected:
	Calculator* calc;
	CalculatorTest() : calc(nullptr) {}

	// virtual void SetUp() {
	void SetUp() override {
		printf("SetUp()\n");
		calc = new Calculator();
	}
};

TEST_F(CalculatorTest, PressPlus_2Plus2_Display4) {
	SPEC("2 더하기 2는 4가 나오는지 검증한다.\n");
	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	ASSERT_EQ(calc->Display(), 4) << "2 + 2 하였을 때";
}

TEST_F(CalculatorTest, Plus) {
	// Act
	calc->Enter(2);
	calc->PressPlus();
	calc->Enter(2);
	calc->PressEquals();

	// Assert
	if (calc->Display() != 4) {
		FAIL();
	} else {
		SUCCEED();
	}
}























































