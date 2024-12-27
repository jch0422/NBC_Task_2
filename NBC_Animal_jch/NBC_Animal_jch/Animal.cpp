#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//makeSound라는 순수 가상함수가 포함된 Animal이라는 부모클래스 생성
class Animal {
public:
	virtual void makeSound() = 0;
};
//makeSound를 재정립하는 자식 클래스 생성
class Dog : public Animal {
public:
	void makeSound() override {//가상함수 재정의
		cout << "bark! bark!" << endl;//울음소리 출력
	}
};

class Cat : public Animal {
public:
	void makeSound() override {
		cout << "Meow Meow" << endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() override {
		cout << "Moo~ Moo~" << endl;
	}
};
//도전과제 ----------------------------------------------------
class Zoo {
private:
	Animal* animals[10];// 동물 객체를 저장하는 포인트 배열
	int count = 0;//현재 동물의 수
public:
	Zoo() {}

	void addAnimal(Animal* animal) {//동물을 동물원에 추가하는 함수
		if (count < 10) {//동물원 배열이 꽉 찼는지 확인
			animals[count] = animal;//안 차있다면 count번호에 맞는 위치에 동물 배치
			count++;
		}
		else
		{
			cout << "동물원이 꽉 찼습니다" << endl;//배열 최대 개수를 초과한다면 돌려보내기
		}
	}
	void performActions() {//모든 동물들이 소리를 내는 함수
		for (int x = 0; x < count; x++) {//현재 보유중인 원소 개수만큼 소리내게하기
			animals[x]->makeSound();
		}
	}
	~Zoo() {
		for (int x = 0; x < count; x++) {//동적 데이터 메모리 정리
			delete animals[x];
		}
	}
};

// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal() {
	// int type = 난수
	int type = rand() % 3;
	// if(type == 0)이라면 new Dog;
	if (type == 0) {
		return new Dog();
	}
	// else if(type == 1)이라면 new Cat;
	else if (type == 1) {
		return new Cat();
	}
	// else if(type == 2)이라면 new Cow;
	else if (type == 2) {//나중에 동물원에 동물의 종류가 늘어나면 확장성을 위해 else if를 사용해봄
		return new Cow();
	}
	//return Animal* 엄.... 어케해야되지그냥 반환하면 되나?
	//Main 함수랑 상호작용 어케함?
}

//main함수에서 Animal클래스의 animals라는 이름의 size = 3의 배열 생성
int main() {
	const int size = 3;
	Animal* animals[size];
	//animals 배열과 각 자식 클래스를 연결(new 키워드를 이용해 동적 메모리를 부여하고 다 사용하면 메모리 정리하기)
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();
	//for문을 이용해서 각 개체별로 makeSound를 한번씩 하게 하고 delete를 이용해 메모리 정리
	for (int x = 0; x < size; x++) {
		animals[x]->makeSound();
	}
	for (int x = 0; x < size; x++) {
		delete animals[x];
	}
	cout << "여기부터는 도전과제" << endl;

	//Zoo랑 상호작용 한다고 생각해보기
	// Zoo클래스를 하나 만들어10개의 원소를 가진 Animal배열이 만들어지겠지?
	// 동물을 추가해줄거야 addAnimal을 써야겠지
	// 근데 난수를 이용해서 랜덤으로 동물 종류를 추가해줄거니까 createRandomAnimal을 써서 addAnimal에 추가해야겠네.
	// 그리고 동물 울음소리를 내게 해
	srand(time(0));
	Zoo jchzoo;
	for (int x = 0; x < 11; x++) {
		Animal* jch = createRandomAnimal();
		jchzoo.addAnimal(jch);
	}
	jchzoo.performActions();
	return 0;
}
