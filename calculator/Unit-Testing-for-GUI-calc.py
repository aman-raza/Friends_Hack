from unittest import TestCase

class TestWindow(TestCase):
    def test_addition(self):
        a= float(input())
        b= float(input())
        c= a+b
        print("Addition should be : "+str(c))
        return self.assertEqual((a+b),c)

    def test_subtraction(self):
        a = float(input())
        b = float(input())
        c = a - b
        print("Subtraction should be : "+str(c))
        return (str(self.assertEqual((a - b), c)))

    def test_multiplication(self):
        a = float(input())
        b = float(input())
        c = a * b
        print("Multiplication should be : "+str(c))
        return self.assertEqual((a * b), c)

    def test_division(self):
        a = float(input())
        b = float(input())
        c = a / b
        print("Division should be : "+str(c))
        return  self.assertEqual((a / b), c)

    def test_square(self):
        a = float(input())
        c = a ** 2
        print("Square should be : "+str(c))
        return self.assertEqual((a * a), c)

    def test_cube(self):
        a = float(input())
        c = a ** 3
        print("Cube should be : "+str(c))
        return self.assertEqual((a * a * a), c)



#        self.fail()
