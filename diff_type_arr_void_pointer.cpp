#include <iostream> 
#include <string>

enum Type {INT, FLOAT, STRING, CHAR, BOOL};

void decide_type(void* ptr, Type eType);
bool is_number(std::string& type);
bool is_float(std::string& type);
int from_string_to_int(std::string& type);
float from_string_to_float(std::string& type);

int main() {
	std::string type{};
	std::cout << "Enter a string for checking a type this value: " << std::endl;
	std::cin >> type;
	std::cout << std::endl;
	if (is_number(type)) {
		std::cout << "The value can be integer, boolean, string or char for int enter i, for boolean enter b, for string enter s, for character enter c:\n" << "ch = ";
		char ch;
		std::cin >> ch;
		std::cout << std::endl;
		switch (ch) {
		case 'i': {
			int num = from_string_to_int(type);
			decide_type(&num, INT);
	 		break;
	    	}
		case 'b': {
			int num = from_string_to_int(type);
			if (num != 0) {
				int num = 1;
				decide_type(&num, BOOL);
				break;
			}
			else {
				int num = 0;
				decide_type(&num, BOOL);
				break;
			}
	     	}
		case 's': {
			char* new_type = new char[type.size() + 1];
			for (int i = 0; i <= type.size(); ++i) {
				new_type[i] = type[i];
			}
			decide_type(new_type, STRING);
			delete[] new_type;
			break;
		   }
		case 'c': {
			if (type.size() == 1) {
				char str = type[0];
				decide_type(&str, CHAR);
				break;
			}
			else {
				std::cout << "Error: Input value can not be char type: " << std::endl;
			}
		   }
		default: {
			std::cout << "Wrong charactor." << std::endl;
		   }
	    }
	}
	else if (is_float(type)) {
		std::cout << "The value can be float or string for float enter f, for string enter s:\n" << "ch = " << std::endl;
		char ch;
		std::cin >> ch;
		std::cout << std::endl;
		switch (ch) {
		case 's': {
			char* new_type = new char[type.size() + 1];
			for (int i = 0; i <= type.size(); ++i) {
				new_type[i] = type[i];
			   }
			decide_type(new_type, STRING);
			delete[] new_type;
			break;
		   }
		case 'f': {
			float num = from_string_to_float(type);
			decide_type(&num, FLOAT);
			break;
		    }
		default: {
			std::cout << "Wrong charactor." << std::endl;
		    }
		}
	}
	else {
		char* new_type = new char[type.size() + 1];
		for (int i = 0; i <= type.size(); ++i) {
			new_type[i] = type[i];
		}
		decide_type(new_type, STRING);
		delete[] new_type;
	}
}	

void decide_type(void* ptr, Type eType) {
	switch (eType) {
	case INT: {
		std::cout << "int = ";
		std::cout << *(int*)ptr << std::endl;
		break;
	}
	case FLOAT: {
		std::cout << "float = ";
		std::cout << *(float*)ptr << std::endl;
		break;
	}
	case STRING: {
		std::cout << "string = ";
		std::cout << (char*)ptr << std::endl;
		break;
	}
	case CHAR: {
		std::cout << "char = ";
		std::cout << *(char*)ptr << std::endl;
		break;
	}
	case BOOL: {
		std::cout << "bool = ";
		std::cout << *(bool*)ptr << std::endl;
		break;
	}
	}
}

float from_string_to_float(std::string& type) {
	return std::stof(type);
}

int from_string_to_int(std::string& type) {
	return std::stoi(type);
}

bool is_number(std::string& type) {
	bool result = false;
	for (int i = 0; i < type.size(); ++i) {
		if (type[i] >= '0' && type[i] <= '9') {
			result = true;
		}
		else {
			return false;
		}
	}
	return result;
}

bool is_float(std::string& type) {
	bool result = false;
	int count = 0;
	for (int i = 0; i < type.size() && type[0] != '.' && type[type.size() - 1] != '.'; ++i) {
		if (type[i] == '.') {
			++count;
		}
	}
	if (count == 1) {
		for (int i = 0; i < type.size(); ++i) {
			if (type[i] >= '0' && type[i] <= '9' || type[i] == '.') {
				result = true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return result;
}