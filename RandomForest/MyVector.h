#pragma once
template<class T>
class MyVector {
public:
	std::vector<T> v;

	MyVector<T> operator+(MyVector<T>&);
	MyVector<T> operator*(MyVector<T>&);
	MyVector<T> operator-(MyVector<T>&);
	MyVector<T> operator/(MyVector<T>&);

	MyVector<T> operator+(T&);
	MyVector<T> operator*(T&);
	MyVector<T> operator-(T&);
	MyVector<T> operator/(T&);

	void print();
};

template<class T>
MyVector<T> MyVector<T>::operator+(MyVector<T>& B) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), B.v.begin(), vec.begin(), plus<T>());
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator*(MyVector<T>& B) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), B.v.begin(), vec.begin(), multiplies<T>());
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator-(MyVector<T>& B) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), B.v.begin(), vec.begin(), minus<T>());
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator/(MyVector<T>& B) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), B.v.begin(), vec.begin(), divides<T>());
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator+(T& b) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), vec.begin(), [&b](T t) {return t + b; });
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator*(T& b) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), vec.begin(), [&b](T t) {return t * b; });
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator-(T& b) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), vec.begin(), [&b](T t) {return t - b; });
	C.v = vec;
	return C;
}

template<class T>
MyVector<T> MyVector<T>::operator/(T& b) {
	MyVector<T> C;
	std::vector<T> vec(B.v.size());
	transform(v.begin(), v.end(), vec.begin(), [&b](T t) {return t / b; });
	C.v = vec;
	return C;
}

template<class T>
void MyVector<T>::print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\t";
	}
	cout << endl;
}

template<class T>
MyVector<MyVector<T>> Zip(MyVector<T> v1, MyVector<T> v2) {
	std::vector<MyVector<T>> v3(v1.v.size());

	transform(v1.v.begin(), v1.v.end(), v2.v.begin(), v3.begin(), [](T t1,T t2) {
		MyVector<T> temp;
		temp.v = { t1,t2 };
		return temp;
	});
	MyVector<MyVector<T>> Myv3;
	Myv3.v = v3;
	return Myv3;
}