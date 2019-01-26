class Singleton {
	static Singleton *instance;
	int data;

	// Private constructor so that no objects can be created.
	Singleton() {
		data = 0;
	}

public:
	static Singleton *getInstance() {
		if (!instance)
			instance = new Singleton;
		return instance;
	}

	int getData() {
		return this->data;
	}

	void setData(int data) {
		this->data = data;
	}
};