#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <ctime>
#include <cstdarg>

void increment(int* x){ // variable address (pointer) parameter
    ++*x;   // increment value at address
}

void takes_array(int* array){    // array parameters decay to pointers of first value, pointer syntax used for clarity
    *array = 10;    // actual value of array changed given pointer parameter
    std::cout << array+1 << '\n';   // sequential int address found using scaling
    *(array+1) = 11;    // pointer arithmetic performed to change sequential value inside array passed
}

void pointers(){
    int x{2};   // variable name x identifier for memory location
    std::cout << &x << '\n';    // & = address-of operator, showing variable memory location
    std::cout << *(&x) << '\n';    // * = indirection operator, showing memory location value

    int* xPtr{&x}; // pointer declaration uses *, pointers only hold address values, type corresponds to variable x
    std::cout << xPtr << '\n';  // memory address of x
    std::cout << *xPtr << '\n'; // value at memory address of x
    *xPtr = 10;
    std::cout << x << '\t' <<  *xPtr << '\n';   // the value at the address of the pointer directly changes the value

    double* ptr{nullptr};  // null pointer, preventing assignment to garbage

    int val{6}; // variable hold 6
    int* valPtr{&val};  // pointer holds address for variable
    increment(valPtr);  // function takes pointer parameter, val = 7
}

void arrayPtr() {
    int array[3]{1, 2, 3};
    std::cout << array << '\n'; // array decays to address of array[0]
    takes_array(array);
    std::cout << array[0] << '\n';    // output value stored at address of array[0]

    const int l{sizeof(array) / sizeof(array[0])};
    for (int i = 0; i < l; ++i) { std::cout << array[i] << '\t'; }
    std::cout << '\n';
}

bool hasA(char ch){
    switch (ch){
        case 'A':
        case 'a':
            return true;
        default:
            return false;
    }
}

int* find(int* start, int* end, int val){
    for (int* p{start}; p != end; ++p){
        if (*p == val){
            return p;
        }
    }
    return end;
}

void charPtr(){
    char name[]{"Sebastian"};
    auto numVowels{ std::count_if(std::begin(name), std::end(name), hasA) };
    // std::count_if counts items that satisfy the condition
    std::cout << name << " has " << numVowels << " a's\n";

    const char* name1{"Seb"};   // pointer to c style string is symbolic constant, stored in ROM
    const char* name2{"Seb"};   // compiler combines these two strings under same address
}

void searchArray(){
    int arr[]{2, 5, 4, 10, 8, 20, 16, 40};
    int* found = find(std::begin(arr), std::end(arr), 20);
    std::cout << "found "<< *found << " at " << found << '\n';
}

const char* getName(){
    return "Sebastian"; // string literal has static duration, dies at end of program, not block
}

void dynamicType(){
    int* ptr{new int};  // ptr allocated an integer and assign the address for access later
    *ptr = 10;  // integer allocated to memory address under ptr
    delete ptr; // free up the dynamically allocated memory to OS
    ptr = nullptr;  // removes value from scope of pointer, prevent dangling pointer
    int* value{new (std::nothrow) int}; // if no memory available from OS, std::nothrow prevents crashing
}

void memoryLeak(){      // memory leak occurs if active pointer goes out of scope, or is assigned a different address
    int x{5};
    int* ptr{new int};
    ptr = &x;   // ptr assigned different address, causing memory leak

    int num{10};
    int* ptr1{new int};
    delete ptr1;
    ptr1 = &num;    // delete pointer before reassignment prevent leak

    int* ptr2{new int};
    ptr2 = new int; // previous int allocation overwriten, creating memory leak
}

void dynamicArray(){
    std::size_t length{};   // std::size_t is used for index values
    std::cout << "array length:"; std::cin >> length;

    int* array{new int[length]{}};    // new[] method for arrays
    for (int i = 1; i <= length; ++i) {
        array[i] = (i*2);
        std::cout << array[i] << '\n';
    }
    delete[] array;   // delete[] method to free memory
}

void getNames(){
    std::size_t length{};   // std::size_t is used for index values
    std::cout << "how many names:"; std::cin >> length;

    std::string* names{new std::string[length]{}};
    for (int i = 0; i < length; ++i) {
        std::string name{};
        std::cout << "Enter Name#" << i+1 << ":";
        std::cin >> name;
        names[i] = name;
    }

    std::sort(names, names + length);

    for (int i = 0; i < length; ++i) {
        std::cout << "Name#" << i+1 << ":" << names[i] << '\n';
    }

    delete[] names;
}

void constPointer(){
    int x{5};
    int y{7};
    const int* ptr1{&x};    // points to a const value, pointer itself is not const
    ptr1 = &y;  // given pointer itself is not const, this is legal

    int* const ptr2{&x};    // const pointer created, address cannot be changed, const after data type
    *ptr2 = 10; // the address of ptr2 is constant, not the value stored underneath, indirection still possible

    const int* const ptr3{&y};    // const pointer to const value possible, no change possible
}

int increaseRef(int& x){    // references used most as function parameters to change variable values
    return ++x; //  references are prefered to pointers for parameters
}

int printArray(int(&array)[4]){  // in order to pass array references as parameters, specify the size
    const int length{sizeof(array) / sizeof(array[0])};
    for (int i = 0; i < length; ++i) {
        std::cout << array[i];
    }
    return 0;
}

void refTest(){
    int x{5};
    int& ref{x};    // a reference must be initialised and cannot be changed to reference another variable
    std::cout << &ref<< '\n' << &x << '\n'; // a reference is an alias for a variable
    const int y{2};
    const int& ref2{y}; // const reference can only be assigned const variables
    const int& numRef{1+2}; // reference allowed to r-value expression
    std::cout << numRef << '\n';

    increaseRef(x);
    std::cout << x << '\n';
    int scores[4]{1, 2, 3, 4};
    printArray(scores);   // when arrays are passed to parameters as references, they dont decay into pointers
}

struct Human{
    int age;
    std::string name;
};

struct Prof{
    Human human;
    std::string subject;
};

void refShortcut(){
    Human fred{};
    int& fredage{fred.age};  // shortcut for writing out full scoping for variable
    fredage = 5;
}

void pointerMembers(){
    Human player{};
    Human* ptr{&player};
    (*ptr).age = 5; // equivalent statements, confusing method for member selectinon
    ptr->age = 5;   // equivalent statements, pointers use arrow member selection operator -> for their members

    Human& ref{player};
    ref.age = 6;    // references can use ordinary member selection operator . for members

    Prof head{};
    Prof* profptr{&head};
    profptr->human.age = 50;    // mix of arrow and dot operator for choosing members
}

int arrayPrint(){
    int array[]{1, 2, 3, 4, 5};
    for (const auto &x : array){    // for-each loop iterates over an array, assigning elements to the given variable
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::string names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string guess{};
    std::cout << "enter a name:";
    std::cin >> guess;
    for (const auto &element:names){
        if (guess == element){
            std::cout << guess << " was found\n";
            return 0;
        }
    }
    std::cout << guess << " was not found\n";
    return 0;
}

enum class Type{    // create an enumeration class for data types
    INT,
    DOUBLE,
    CSTRING
};

void printValue(void* ptr, Type type){  // void (general) pointer can take any data type
    switch (type) {
        case Type::INT: // enum class requires strongly typed member
            std::cout << *static_cast<int*>(ptr) << '\n';
            break;
        case Type::DOUBLE:
            std::cout << *static_cast<double*>(ptr) << '\n';
            break;
        case Type::CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n';
            break;
    }
}

void voidpointers(){
    int iVal{10};
    double dVal{50.5};
    char cVal[]{"c_string"};

    printValue(&iVal, Type::INT);
    printValue(&dVal, Type::DOUBLE);
    printValue(cVal, Type::CSTRING);    // c style string decays to pointer address, therefore & operator not needed
}

void pointerpointer(){
    int x{5};
    int* ptr1{&x};
    int** ptr2 = &ptr1; // pointer for the address of ptr1, ** assignment
    std::cout << ptr1 << ' ' << ptr2 << '\n';    // address values
    std::cout << *ptr1 << ' ' << **ptr2 << '\n';    // values under the address, indirection ** for pointer pointer

    int** array = new int*[10]; // dynamically allocating an array of pointers, 10 rows
    for (int i = 0; i < 10; ++i) {
        array[i] = new int[5];  // dynamically allocating column to each row
    }
}

int flatArrayIndexing(int row, int col){
    return (row * col);
}

void flattenedArray(){
    auto array = new int[10][5]; // this dynamic 2d array requires first index to be a compile time constant
    int* flatarray = new int[50];   //  this is the same array, flattened out into one dimension

    array[7][2] = 5; // allocating 7th row, 2nd column
    flatarray[flatArrayIndexing(7, 2)] = 5; // same operation using function
    std::cout << flatarray[14] << '\n';
}

void arraymanage(std::array<int, 4> &array){ // always pass std::array by reference
    std::sort(array.begin(), array.end());
    for (int x:array) {
        std::cout << x << ", ";
    }
    std::cout << "length=" << array.size() << '\n'; // .size() function gets length of std::array
}

void arraysequel(){ // std::array are safer and easier to use fixed arrays
    std::array<int, 4> array1{1, 2, 3, 4};  // type and length must be given together if directly initialised
    array1[0] = 9;   // indexing works as normal
    std::array<int, 4> array2{1, 2, 3}; // omitted values are zero initialised
    array2.at(0) = 9;   // indexing utilising range checking, error if out of range
    arraymanage(array1);
    arraymanage(array2);    // .size() outputs type std::size_t

    for (std::size_t i{}; i < array1.size(); ++i) { // notice data type of iterator given .size() function output
        std::cout << array1[i];
    }
    std::cout << '\n';

    std::array<Human, 2> apt1; // std::array can use struct type aswell
    apt1.at(0) = {32, "fred"};
    apt1.at(1) = {30, "julia"};

    for (const Human& h : apt1) {  // const for performance
        std::cout << h.age << ' ' << h.name << '\n';
    }
}

void takevector(std::vector<int> &v){
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << v.at(i) << " ";
    }
    std::cout << '\n';
}

int standardvector(){  // std::vector makes dynamic arrays safer and easier
    std::vector<int> vector{1, 2, 3}; // length defined in run-time, memory dynamically allocated
    vector.at(0) = 0;    // .at() funtionality, range checking, error thrown if invalid range chosen
    vector = {1, 2, 3, 4, 5};    // allowed, std::vector type changes size dynamically

    takevector(vector);
    vector.resize(7);   // easily changes the size of dynamically sized array, bigger or smaller

    return 0;   // vector goes out of range, memory automatically deallocated
}

inline int max_int(int x, int y){   // inline functions have one defintion per program, avoiding conflicts
    return (x > y) ? x : y; // short inline function prevent excessive code bloat upon compile
}

int simpleFunc(){
    const int sum1{max_int(5, 2)};  // two simple statements make use of the inline function
    int sum2{max_int(sum1, 10)};    // reducing function overhead runtime of normal function calls
    std::cout << sum2 << '\n';  // the inline function code is substituted for the call
    return sum2;
}

int add(int x, int y){  // first definition of int add()
    return x + y;
}

int add(int x, int y, int z){   // second definition of int add(), multiple functions with the same name
    return x + y + z;   // different parameters or return type create function overloading
}   // function overloading does not apply for return type variables, compile error occurs

int randRange(int min=1, int max=6){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // system clock seed
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};  // static used for efficiency
    int output = min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    return output;
}

int outputVal(int x=1); // forward declarations can initialise the default value or function body, not both

int outputVal(int x){
    return x;
}

char outputVal(char c=' '){ // function overloading can be used with default parameters for convenience
    return c;
}

void defaultParameters(){
    std::cout << randRange() << '\n';   // no parameter values given, defaults in function used
    std::cout << randRange(2) << '\n';  // min parameter overwritten with argument value
    std::cout << randRange(0,5) << '\n';    // both default parameters overwritten
    std::cout << outputVal(5) << '\n';
    std::cout << outputVal('s') << '\n';
}

int someOp(int x){
    return ++x;
}

void functionPointer(){
    std::cout << reinterpret_cast<void*>(defaultParameters) << '\n';    // output function address
    void (*funcptr)(){&defaultParameters};  // pointer towards function address, types must match
    (*funcptr)();   // calls function through pointer, explicit dereference
    funcptr = &arraysequel; // reassigning the pointer value
    int (*const funcptr2)(int){someOp}; // const pointer made for function with int parameter
    std::cout << (*someOp)(5) << '\n';  // explicit dereference
    std::cout << someOp(5) << '\n';  // implicit dereference

    bool (*someFunc)(); // empty function pointer of bool type
    auto (*anotherFunc)(int){someOp};  // auto keyboard usefull for function pointers
}

void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int)){  // empty function pointer as parameter
    for (int startIndex{0}; startIndex < (size - 1); ++startIndex){
        int bestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex){
            if (comparisonFcn(array[bestIndex], array[currentIndex])){
                bestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[bestIndex]);
    }
}

bool ascending(int x, int y){
    return x > y;
}

void printArray(int *array, int size){
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
}

void countdown(int x){
    std::cout << "T-" << x << '\n';
    if (x > 0){
        countdown(--x); // recursive function calls itself, include a termination statement to prevent infinite loops
    }
}

int fibonacci(int find){    // recursive sequence
    if (find == 0){
        return 0;
    }
    if (find == 1){
        return 1;
    }
    return fibonacci(find - 1) + fibonacci(find - 2);
}

void sequence(){
    int total{10};
    for (int i = 0; i < total; ++i) {
        std::cout << fibonacci(i) << " ";
    }
}

int unknownParameters(int count, ...){  // ellipsis allows multiple arguments in place
    double sum{};
    va_list list;   // ellipsis accessed through va_list
    va_start(list, count);  // va_list initialised in va_start
    for (int arg = 0; arg < count; ++arg) {
        sum += va_arg(list, int);   // va_arg gets value out of ellipsis, out of list, type int
    }

    va_end(list);   // cleanup va_list when finished
    return sum / count;
}

void testellipsis(){
    std::cout << unknownParameters(3, 1, 2, 3) << '\n'; // takes four arguments, two parameters defined
    std::cout << unknownParameters(5, 10, 52, 48, 12, 99) << '\n';
}

void lambdas(std::vector<int> &x){ // lambdas are anonymous function objects right at the location where invoked
    std::sort(x.begin(), x.end(),
              [](int a, int b){return(std::abs(a) < std::abs(b));}    // lambda passed as third argument to function
              );
    takevector(x);

    auto descend{   // lambdas can be stored under variable names, lambda type is unexposed
        [](int a, int b){return(std::abs(a) > std::abs(b));}
    };
    std::sort(x.begin(), x.end(), descend);
    takevector(x);

    double (*addNumber)(double, double){    // function pointer store lambdas without capture clause
            [](double a, double b){return a + b;}
    };
    double value{addNumber(5, 6)};

    auto genericlambda{ // generic lambda function given auto parameter allowing wide range of inputs
        [](auto value){
            static int callCount{0};    // static variable tracks same data type calls
            std::cout << callCount++ << ": " << value << '\n';
        }
    };

    genericlambda("first");
    genericlambda("second");
    genericlambda(6);

    auto multiplereturn{
        [](int a, int b, bool type) -> double { // using the trailing return type indicates all return types are double
            if (type){
                return a / b;
            }
            return static_cast<double>(a) / b;  // without trailing type, inference not possible, compiler error
        }
    };

    std::cout << multiplereturn(5, 2, true) << '\n';
    std::cout << multiplereturn(5, 2, false) << '\n';
}

void captureclause(){
    int ammo{30};
    auto shoot{
        [ammo]() mutable {  // clause parameters are const copies, mutable keyword removes const
            std::cout << --ammo << " ammo left\n";
        }
    };
    shoot();
    shoot();

    auto shoot2{
        [&ammo](){  // reference clause parameter change original variable
            std::cout << --ammo << " ammo left\n";
        }
    };
    shoot2();
    shoot2();

    /* [=](){};    // clause parameter = takes all variables by value
    [&](){};    // clause parameter & takes all variables by reference
    [=, &ammo](){};    // other variables by value, ammo by reference, default capture first term
    [&, ammo](){};    // other variables by reference, ammo by value
    */
}

int main(){
    captureclause();
    return 0;
}