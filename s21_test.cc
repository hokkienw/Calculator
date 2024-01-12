#include <gtest/gtest.h>

#include <string>

#include "app/controller/controller.h"
#include "app/controller/creditcontroller.h"
#include "app/controller/debitcontroller.h"
#include "app/model/creditmodel.h"
#include "app/model/debitmodel.h"
#include "app/model/model.h"

using namespace s21;

class CalcTest : public testing::Test {
 public:
  s21::StandCalcModel model;
  std::string result = "0";
  double x_value = 0;
};

TEST_F(CalcTest, test_case_1) {
  s21::Controller controller(&model);
  std::string input_str = "1+2*3";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_2) {
  s21::Controller controller(&model);
  std::string input_str = "2.0/(3.0+2.0)*5.0";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2");
}

TEST_F(CalcTest, test_case_3) {
  s21::Controller controller(&model);
  std::string input_str = "1+2+(3*4)+(5.1+6.8)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "26.9");
}

TEST_F(CalcTest, test_case_4) {
  s21::Controller controller(&model);
  std::string input_str = "10.0+10.0*10.0";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "110");
}

TEST_F(CalcTest, test_case_5) {
  s21::Controller controller(&model);
  std::string input_str = "5.0mod3.0";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2");
}

TEST_F(CalcTest, test_case_6) {
  s21::Controller controller(&model);
  std::string input_str = "1.0/2.0*(2.0-1.0)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.5");
}

TEST_F(CalcTest, test_case_7) {
  s21::Controller controller(&model);
  std::string input_str = "(1-2-(0-3)-4)-5-(0-6)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-1");
}

TEST_F(CalcTest, test_case_8) {
  s21::Controller controller(&model);
  std::string input_str = "(1+2)*((3-4)+1+(5-6+7))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "18");
}

TEST_F(CalcTest, test_case_9) {
  s21::Controller controller(&model);
  std::string input_str = "sqrt(4)-1/2*sin(3^2-2)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "1.671507");
}

TEST_F(CalcTest, test_case_10) {
  s21::Controller controller(&model);
  std::string input_str = "2^3^2";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "512");
}

TEST_F(CalcTest, test_case_11) {
  s21::Controller controller(&model);
  std::string input_str = "sin(+3)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.14112");
}

TEST_F(CalcTest, test_case_12) {
  s21::Controller controller(&model);
  std::string input_str = "-1+8";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_13) {
  s21::Controller controller(&model);
  std::string input_str = "-5.0mod(-3.0)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-2");
}

TEST_F(CalcTest, test_case_14) {
  s21::Controller controller(&model);
  std::string input_str = "4+4*2/(1-5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2");
}

TEST_F(CalcTest, test_case_15) {
  s21::Controller controller(&model);
  std::string input_str = "4+4*2/1-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_16) {
  s21::Controller controller(&model);
  std::string input_str = "4+4*(2/1-5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-8");
}

TEST_F(CalcTest, test_case_17) {
  s21::Controller controller(&model);
  std::string input_str = "4+(4*2/1-5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_18) {
  s21::Controller controller(&model);
  std::string input_str = "4+4*(2/1)-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_19) {
  s21::Controller controller(&model);
  std::string input_str = "4+(4*2/1)-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_20) {
  s21::Controller controller(&model);
  std::string input_str = "(4+4)*(2/1)-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "11");
}

TEST_F(CalcTest, test_case_21) {
  s21::Controller controller(&model);
  std::string input_str = "(4+4)*(2/1)-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "11");
}

TEST_F(CalcTest, test_case_22) {
  s21::Controller controller(&model);
  std::string input_str = "(4+4*2)/1-5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "7");
}

TEST_F(CalcTest, test_case_23) {
  s21::Controller controller(&model);
  std::string input_str = "8*(7+6*4)+3";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "251");
}

TEST_F(CalcTest, test_case_24) {
  s21::Controller controller(&model);
  std::string input_str = "2/(3+2)*5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2");
}

TEST_F(CalcTest, test_case_25) {
  s21::Controller controller(&model);
  std::string input_str = "2+9.3-8^3/4+56.2";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-60.5");
}

TEST_F(CalcTest, test_case_26) {
  s21::Controller controller(&model);
  std::string input_str = "2+9.3-8^3/(4+56.2)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2.795017");
}

TEST_F(CalcTest, test_case_27) {
  s21::Controller controller(&model);
  std::string input_str = "2^(3^2)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "512");
}

TEST_F(CalcTest, test_case_28) {
  s21::Controller controller(&model);
  std::string input_str = "(2^3)^2";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "64");
}

TEST_F(CalcTest, test_case_29) {
  s21::Controller controller(&model);
  std::string input_str = "cos(431.2*2^2/8)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-0.3902501");
}

TEST_F(CalcTest, test_case_30) {
  s21::Controller controller(&model);
  std::string input_str = "3*sin(4+5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "1.236355");
}

TEST_F(CalcTest, test_case_31) {
  s21::Controller controller(&model);
  std::string input_str = "431.2*2^2/8";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "215.6");
}

TEST_F(CalcTest, test_case_32) {
  s21::Controller controller(&model);
  std::string input_str = "cos(sin(2+9*6^1.2-tan(1)))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.7421823");
}

TEST_F(CalcTest, test_case_33) {
  s21::Controller controller(&model);
  std::string input_str = "sqrt(cos(sin(2+9*6^1.2-tan(1))))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.8615");
}

TEST_F(CalcTest, test_case_35) {
  s21::Controller controller(&model);
  std::string input_str = "sqrt(2^2)*5/(4-3mod2)*(4-sqrt(81))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "-16.66667");
}

TEST_F(CalcTest, test_case_36) {
  s21::Controller controller(&model);
  std::string input_str = "cos(1/3)*sin(1.352^9/(4+3))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.7876032");
}

TEST_F(CalcTest, test_case_37) {
  s21::Controller controller(&model);
  std::string input_str = "(cos(1/3)*sin(1.352^9/(4+3))/76.56)*log(150)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.02238632");
}

TEST_F(CalcTest, test_case_38) {
  s21::Controller controller(&model);
  std::string input_str = "2+(-(-(-(-1))))";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "3");
}

TEST_F(CalcTest, test_case_39) {
  s21::Controller controller(&model);
  std::string input_str = "cos(6*3)/5";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.1320633");
}

TEST_F(CalcTest, test_case_43) {
  s21::Controller controller(&model);
  std::string input_str = "acos(1)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0");
}

TEST_F(CalcTest, test_case_44) {
  s21::Controller controller(&model);
  std::string input_str = "acos(0.5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "1.047198");
}

TEST_F(CalcTest, test_case_45) {
  s21::Controller controller(&model);
  std::string input_str = "atan(1)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.7853982");
}

TEST_F(CalcTest, test_case_46) {
  s21::Controller controller(&model);
  std::string input_str = "atan(15)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "1.504228");
}

TEST_F(CalcTest, test_case_47) {
  s21::Controller controller(&model);
  std::string input_str = "asin(1)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "1.570796");
}

TEST_F(CalcTest, test_case_48) {
  s21::Controller controller(&model);
  std::string input_str = "asin(0.5)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0.5235988");
}

TEST_F(CalcTest, test_case_49) {
  s21::Controller controller(&model);
  std::string input_str = "ln(1)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "0");
}

TEST_F(CalcTest, test_case_50) {
  s21::Controller controller(&model);
  std::string input_str = "ln(15)";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "2.70805");
}

TEST_F(CalcTest, test_case_51) {
  s21::Controller controller(&model);
  std::string input_str = "x+15";
  x_value = 2;
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "17");
}

TEST_F(CalcTest, test_case_52) {
  s21::Controller controller(&model);
  std::string input_str = "x^2+x*2";
  x_value = 3;
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "15");
}

TEST_F(CalcTest, test_case_61) {
  s21::Controller controller(&model);
  std::string input_str = "2E+2-2E-1";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "199.8");
}

TEST_F(CalcTest, test_case_66) {
  s21::Controller controller(&model);
  std::string input_str = "3^(1^1)^2";
  result = controller.Calculate(input_str, x_value);
  EXPECT_EQ(result, "3");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
