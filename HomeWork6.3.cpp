/*
Степанян Григорий
Visual Studio 2019

1.Создать абстрактный класс Figure (фигура).
Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

2.Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус).
От этих классов наследует класс Minivan (минивэн).
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

3.Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
Предусмотреть, чтобы знаменатель не был равен 0.
Перегрузить : математические бинарные операторы (+, -, *, /) для выполнения действий с дробями,
унарный оператор (-),
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.

4.Создать класс Card, описывающий карту в игре БлэкДжек.
У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
Сделать поля масть и значение карты типом перечисления (enum).
Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
#include <iostream>

class Figure 
{
public:
	virtual void area() = 0;
};

class Parallelogram : public Figure 
{
protected:
	double m_height;
	double m_base;
public:
	Parallelogram(double base) : m_base(base)
	{

	}
	Parallelogram(double height, double base) : m_height(height), m_base(base)
	{

	}
	void area()
	{
		std::cout << "Parallelogram area is " << m_height * m_base << std::endl;
	}
};

class Circle : public Figure
{
private:
	const double m_pi = 3.1428;
	double m_radius;
public:
	Circle(double radius) : m_radius(radius)
	{

	}
	void area()
	{
		std::cout << "Circle area is " << m_pi * m_radius * m_radius << std::endl;
	}
};
class Rectangle : public Parallelogram
{
private:
	double m_width;
public:
	Rectangle(double base , double width) : Parallelogram(base), m_width(width)
	{

	}
	void area()
	{
		std::cout << "Rectangle area is " << m_base * m_width << std::endl;
	}
};

class Square : public Parallelogram
{
public:
	Square(double base) : Parallelogram(base)
	{

	}
	void area()
	{
		std::cout << "Square area is " << m_base * m_base << std::endl;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double height, double base) : Parallelogram(height, base)
	{

	}
	void area()
	{
		std::cout << "Rhombus area is " << m_height * m_base << std::endl;
	}
};

class Car
{
protected:
	std::string m_company;
	std::string m_model;
public:
	Car(std::string company, std::string model) : m_company(company), m_model(model)
	{
		std::cout << "Car is " << m_company << " " << m_model << std::endl;
	}
};
class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "PassengerCar is " << m_company << " " << m_model << std::endl;
	}
};
	
class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "Bus is " << m_company << " " << m_model << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model) : PassengerCar(company, model),Bus(company, model) , Car(company, model)
	{
		std::cout << "Minivan is " << m_company << " " << m_model << std::endl;
	}
};

class Fraction
{
private:
	int m_numirator = 0;
	int m_denominator = 1;
public:
	Fraction(int numirator = 0, int denominator = 1) : m_numirator(numirator), m_denominator(denominator)
	{
		reduce();
	}
	static int nod(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}

	void reduce()
	{
		int nod = Fraction::nod(m_numirator, m_denominator);
		m_numirator /= nod;
		m_denominator /= nod;
	}
	Fraction operator+ (const Fraction& f2) const;
	Fraction operator- (const Fraction& f2) const;
	Fraction operator* (const Fraction& f2) const;
	Fraction operator/ (const Fraction& f2) const;
	Fraction operator- () const;
	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator!= (const Fraction& f1, const Fraction& f2);
	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator<= (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);

	void print()
	{
		std::cout << m_numirator << "/" << m_denominator << std::endl;
	}
};

Fraction Fraction:: operator+ (const Fraction& f2) const
{
	return Fraction(m_numirator * f2.m_denominator + f2.m_numirator * m_denominator, m_denominator * f2.m_denominator);
}
Fraction Fraction:: operator- (const Fraction& f2) const
{
	return Fraction(m_numirator * f2.m_denominator - f2.m_numirator * m_denominator, m_denominator * f2.m_denominator);
}
Fraction Fraction:: operator* (const Fraction& f2) const
{
	return Fraction(m_numirator * f2.m_numirator, m_denominator * f2.m_denominator);
}
Fraction Fraction:: operator/ (const Fraction& f2) const
{
	return Fraction(m_numirator * f2.m_denominator, m_denominator * f2.m_numirator);
}
Fraction Fraction:: operator- () const
{
	return Fraction(-m_numirator, m_denominator);
}

bool operator== (const Fraction& f1, const Fraction& f)
{
	return ((f1.m_numirator == f.m_numirator) && (f1.m_denominator == f.m_denominator));
}
bool operator!= (const Fraction& f1, const Fraction& f2)
{
	return ((f1.m_numirator != f2.m_numirator) && (f1.m_denominator != f2.m_denominator));
}
bool operator< (const Fraction& f1, const Fraction& f2)
{
	return ((double)f1.m_numirator / f1.m_denominator ) < ((double)f2.m_numirator / f2.m_denominator);
}
bool operator> (const Fraction& f2, const Fraction& f)
{
	return ((double)f2.m_numirator / f2.m_denominator) > ((double)f.m_numirator / f.m_denominator);
}
bool operator<= (const Fraction& f2, const Fraction& f)
{
	return !(f2 > f);
}
bool operator>= (const Fraction& f1, const Fraction& f2)
{
	return !(f1 < f2);
}

class Card
{
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};

	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
	CardRank m_rank;
	CardSuit m_suit;
	bool m_faceCard;
public:
	Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS, bool faceCard = false) : m_rank(rank), m_suit(suit), m_faceCard(faceCard)
	{

	}

	bool Flip()
	{
		return (m_faceCard == true) ? false : true;
	}

	int GetValue() const
	{
		switch (m_rank)
		{
		case Card::RANK_2: return 2;
		case Card::RANK_3: return 3;
		case Card::RANK_4: return 4;
		case Card::RANK_5: return 5;
		case Card::RANK_6: return 6;
		case Card::RANK_7: return 7;
		case Card::RANK_8: return 8;
		case Card::RANK_9: return 9;
		case Card::RANK_10: return 10;
		case Card::RANK_JACK: return 10;
		case Card::RANK_QUEEN: return 10;
		case Card::RANK_KING: return 10;
		case Card::RANK_ACE: return 1;
		default:
			break;
		}
	}
};


int main()
{
	Parallelogram parallelogram(10, 5);
	parallelogram.area();

	Circle circle(5);
	circle.area();

	Rectangle rectangle(10,5);
	rectangle.area();

	Square square(10);
	square.area();

	Rhombus romb(10,5);
	romb.area();

	Minivan minivan("Mercedez - Benz", "V-class");

	Fraction f(2, 4);
	f.print();
	Fraction f1(1, 2);
	f1.print();
	Fraction f2(2, 3);
	f2.print();
	Fraction f3 = f1 + f2;
	f3.print();
	Fraction f4 = f1 - f2;
	f4.print();
	Fraction f5 = f1 * f2;
	f5.print();
	Fraction f6 = f1 / f2;
	f6.print();
	Fraction f7 = -f1;
	f7.print();
	if (f1 == f)
	{
		std::cout << "f1 == f" << std::endl;
	}
	if (f1 != f2)
	{
		std::cout << "f1 != f2" << std::endl;
	}
	if (f1 < f2)
	{
		std::cout << "f1 < f2" << std::endl;
	}
	if (f2 > f)
	{
		std::cout << "f2 > f" << std::endl;
	}
	if (f2 <= f)
	{
		std::cout << "f2 <= f" << std::endl;
	}
	if (f1 >= f2)
	{
		std::cout << "f1 >= f2" << std::endl;
	}

	Card card;
	std::cout << card.GetValue() << std::endl;
	return 0;
}