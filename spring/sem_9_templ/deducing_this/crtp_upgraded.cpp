#include <iostream>


// template <typename Implementation>
struct ParserInterface {

	template <typename Self>
	std::pair<int, int> parseFile(this Self&& self) {
		// hard work...
		return {std::forward<Self>(self).getData(), std::forward<Self>(self).getID()};
	}
	
    int getData() {
		std::cout << "ParserInterface::getData()\n";
		return 0;
    }

    int getID() = delete; //{
//		std::cout << "ParserInterface::getID()\n";
//        return 0;
//    }

// private:
/*
    Implementation* impl() {
        return static_cast<Implementation*>(this);
    }
*/
};

struct ParserJsonImpl : public ParserInterface {
//	friend class ParserInterface<ParserJsonImpl>;
// private:
    int getData() {
        std::cout << "ParserJsonImpl::getData()\n";
        return 0;
    }

    int getID() {
        std::cout << "ParserJsonImpl::getID()\n";
        return 0;
    }
};

struct ParserXmlImpl : public ParserInterface {

    int getData() {
        std::cout << "ParserXmlImpl::getData()\n";
        return 0;
    }

    int getID() {
        std::cout << "ParserXmlImpl::getID()\n";
        return 0;
    }
};


int main() {

    ParserJsonImpl jsonParser;
    jsonParser.parseFile();

    ParserXmlImpl xmlParser;
    xmlParser.parseFile();

    return 0;
}
