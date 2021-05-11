#include <iostream>
#include <algorithm>
#include <string>

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

int main(){
    arrayPrint();
    return 0;
}