
void print(int);
void print(int* const);

bool unlucky(double, int*);

void lucky();

int main() {

    print(42);
    lucky();
    unlucky(1, nullptr);
    print(nullptr);
    return 0;
}
