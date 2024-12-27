#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//makeSound��� ���� �����Լ��� ���Ե� Animal�̶�� �θ�Ŭ���� ����
class Animal {
public:
	virtual void makeSound() = 0;
};
//makeSound�� �������ϴ� �ڽ� Ŭ���� ����
class Dog : public Animal {
public:
	void makeSound() override {//�����Լ� ������
		cout << "bark! bark!" << endl;//�����Ҹ� ���
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
//�������� ----------------------------------------------------
class Zoo {
private:
	Animal* animals[10];// ���� ��ü�� �����ϴ� ����Ʈ �迭
	int count = 0;//���� ������ ��
public:
	Zoo() {}

	void addAnimal(Animal* animal) {//������ �������� �߰��ϴ� �Լ�
		if (count < 10) {//������ �迭�� �� á���� Ȯ��
			animals[count] = animal;//�� ���ִٸ� count��ȣ�� �´� ��ġ�� ���� ��ġ
			count++;
		}
		else
		{
			cout << "�������� �� á���ϴ�" << endl;//�迭 �ִ� ������ �ʰ��Ѵٸ� ����������
		}
	}
	void performActions() {//��� �������� �Ҹ��� ���� �Լ�
		for (int x = 0; x < count; x++) {//���� �������� ���� ������ŭ �Ҹ������ϱ�
			animals[x]->makeSound();
		}
	}
	~Zoo() {
		for (int x = 0; x < count; x++) {//���� ������ �޸� ����
			delete animals[x];
		}
	}
};

// ���� ������ �����ϴ� �Լ�
// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
// - �Է� �Ű�����: ����
// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
Animal* createRandomAnimal() {
	// int type = ����
	int type = rand() % 3;
	// if(type == 0)�̶�� new Dog;
	if (type == 0) {
		return new Dog();
	}
	// else if(type == 1)�̶�� new Cat;
	else if (type == 1) {
		return new Cat();
	}
	// else if(type == 2)�̶�� new Cow;
	else if (type == 2) {//���߿� �������� ������ ������ �þ�� Ȯ�强�� ���� else if�� ����غ�
		return new Cow();
	}
	//return Animal* ��.... �����ؾߵ����׳� ��ȯ�ϸ� �ǳ�?
	//Main �Լ��� ��ȣ�ۿ� ������?
}

//main�Լ����� AnimalŬ������ animals��� �̸��� size = 3�� �迭 ����
int main() {
	const int size = 3;
	Animal* animals[size];
	//animals �迭�� �� �ڽ� Ŭ������ ����(new Ű���带 �̿��� ���� �޸𸮸� �ο��ϰ� �� ����ϸ� �޸� �����ϱ�)
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();
	//for���� �̿��ؼ� �� ��ü���� makeSound�� �ѹ��� �ϰ� �ϰ� delete�� �̿��� �޸� ����
	for (int x = 0; x < size; x++) {
		animals[x]->makeSound();
	}
	for (int x = 0; x < size; x++) {
		delete animals[x];
	}
	cout << "������ʹ� ��������" << endl;

	//Zoo�� ��ȣ�ۿ� �Ѵٰ� �����غ���
	// ZooŬ������ �ϳ� �����10���� ���Ҹ� ���� Animal�迭�� �����������?
	// ������ �߰����ٰž� addAnimal�� ��߰���
	// �ٵ� ������ �̿��ؼ� �������� ���� ������ �߰����ٰŴϱ� createRandomAnimal�� �Ἥ addAnimal�� �߰��ؾ߰ڳ�.
	// �׸��� ���� �����Ҹ��� ���� ��
	srand(time(0));
	Zoo jchzoo;
	for (int x = 0; x < 11; x++) {
		Animal* jch = createRandomAnimal();
		jchzoo.addAnimal(jch);
	}
	jchzoo.performActions();
	return 0;
}
