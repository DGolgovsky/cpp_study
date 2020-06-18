#include <vector>
#include <mutex>

class Vertex
{
};

class Polygon
{
private:
	std::vector <Vertex> vertices;
	mutable double cachedArea{0};
	mutable std::mutex mutex;
public:
	//...

	/* Компилятор не даст провернуть подобный фокус, ведь метод area()
	 * помечен константным, а мы зачем-то пытаемся в нём изменять свойство
	 * cachedArea.
	 *
	 * ...В данном случае компилятор снова начнёт жаловаться на метод
	 * area(), который бодро обещает быть константным, но сам пытается
	 * выполнить операцию mutex::lock(), которая меняет состояние мьютекса.
	 *
	 * Ключевое слово mutable существует в стандарте языка С++ именно для
	 * решения данного класса проблем. Его можно добавить к переменным
	 * членам класса для указания того, что данная переменная может
	 * изменяться даже в константном контексте.
	 */
	double area() const {
		auto area = cachedArea;
		if (area == 0) {
			std::scoped_lock lock{mutex};
			area = geometry::calculateArea(vertices);
			cachedArea = area;
		}
		return area;
	}

	void resetCache() {
		assert(!mutex.try_lock());
		cachedArea = 0;
	}

	void add(Vertex const &vertex) {
		std::scoped_lock lock{mutex};
		resetCache();
		vertices.push_back(vertex);
	}

	//...
};

/*
 * Есть и ещё один вариант применения ключевого слова mutable и он связан
 * с сохранением состояния в лямбда-функциях. Обычно оператор вызова
 * функции замыкания является константным. Другими словами — лямбда не
 * может модифицировать переменные, захваченные по значению.
 */
int main() {
	int i = 2;
	auto ok = [&i]() { ++i; }; //OK, i захватывается по ссылке
	auto err = [i]() { ++i; }; //Ошибка: попытка изменения внутренней копии i
	auto err2 = [x{22}]() { ++x; }; //Ошибка: попытка изменения внутренней переменной x

/*
 * Но ключевое слово mutable может быть применено ко всей лямбда-функции,
 * что сделает все её переменные изменяемыми.
 */
	i = 2;
	auto ok = [i, x{22}]() mutable {
		i++;
		x += i;
	};
}
/*
 * Следует заметить, что в отличии от mutable-переменных в объявлении
 * класса, мутабельные лямбда-функции должны использоваться относительно
 * редко и очень аккуратно. Сохранение состояния между вызовами
 * лямбда-функции может быть опасным и контринтуитивным.
 */
