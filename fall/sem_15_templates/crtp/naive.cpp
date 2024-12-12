

// Функция, принимающая реализацию абстрактного интерфейса Parser в виде указателя
// и файл, возвращающая данные в обработанном виде
ParsedDataType parseData(Parser* parser, FileType file);

int main() {
    FileType file = readFile();
    Parser* impl = nullptr;
    if (file.type() == JsonFile)
        impl = new ParserJsonImpl();
    else
        impl = new ParserXmlImpl();
    ParsedDataType parsedData = parserData(impl, file);
}
