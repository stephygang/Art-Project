// UMBC - CMSC 341 - Spring 2026 - Proj0
#include <iomanip>

#include "art.h"

class Tester{
    public:
    // the following tests the normal case of create() function
    bool testDefault(Art & art);
    bool testCreateNormal(Art & art);
    // the following tests the negative case of create() function
    bool testCreateNegative(Art & art);
    bool testCreateEdgeCase(Art & art);
    bool testCopy(const Art & copy, const Art & original);
    bool testAddress(const Art & copy, const Art & original);
    bool testLeft2Right(Art & left, Art & right);

    private:
    /******************************************
    * Test function declarations go here! *
    ******************************************/
};

int main() {
    // the following is a sample usage of the Art class
    // we create two objects and append them
    cout << "\nSample usage of the Art class:\n\n";
    Art art1(5,10);
    art1.create(10);
    cout << endl << "Dump of a 5x10 object:\n\n";
    art1.dumpColors("\u2588");// prints a box
    art1.dumpValues();


    Art art2(5,10);
    art2.create(5);
    cout << endl << "Dump of a 5x10 object:\n\n";
    art2.dumpColors("\u2588");
    art2.dumpValues();

    art1.top2Bottom(art2);
    cout << endl << "Dump of the append result (10x10):\n\n";
    art1.dumpColors("\u2588");
    cout << endl << "Dump of the append result (10x10) values:\n\n";
    art1.dumpValues();

    // g++ -o mytest mytest.cpp art.cpp

    Tester tester;// test object
    {
        // [1] testing create function for normal case
        Art art(10,10);
        cout << "\nTesting the normal case of create function:\n\n";
        if (tester.testCreateNormal(art) == true)
            cout << "\tNormal case of create passed!\n";
        else
            cout << "\tNormal case of create failed!\n";




        // [2] testing default constructor
        Art defaultArt;

        cout << "\nTesting the default constructor:\n\n";
        if (tester.testDefault(defaultArt) == true)
            cout << "\tDefault case of default constructor passed!\n";
        else
            cout << "\tDefault case of default constructor failed!\n";




        // [3] test constructor
        Art copy(art);

        cout << "\nTesting the copy with the create function:\n\n";
        if (tester.testCreateNormal(copy) == true)
            cout << "\tNormal case of create passed!\n";
        else
            cout << "\tNormal case of create failed!\n";




        cout << "\nTesting the copy constructor:\n\n";
        if (tester.testCopy(copy, art) == true) {
            cout << "\tCopy case of copy passed!\n";

            cout << endl << "Dump of the copy object:\n\n";
            copy.dumpColors("\u2588");// prints a box
            copy.dumpValues();

            cout << endl << "Dump of the original object:\n\n";
            art.dumpColors("\u2588");// prints a box
            art.dumpValues();
        }
        else
            cout << "\tCopy case of copy failed!\n";





        cout << "\nTesting the copy and the original have different memory addresses:\n\n";
        if (tester.testAddress(copy, art) != true)
            cout << "\tDifferent memory address. Passed!\n";
        else
            cout << "\tSame memory address. Failed!\n";




        Art errorCase(-1, 10);
        Art errorCase2(1, -10);
        Art errorCase3(-1, -10);
        cout << "\nTesting the error case of the create function (1):\n\n";
        if (tester.testCreateNormal(errorCase) != true)
            cout << "\tError case (1) of create passed!\n";
        else
            cout << "\tError case (1) of create failed!\n";

        cout << "\nTesting the error case of the create function (2):\n\n";
        if (tester.testCreateNormal(errorCase2) != true)
            cout << "\tError case (2) of create passed!\n";
        else
            cout << "\tError case (2) of create failed!\n";

        cout << "\nTesting the error case of the create function (3):\n\n";
        if (tester.testCreateNormal(errorCase3) != true)
            cout << "\tError case (3) of create passed!\n";
        else
            cout << "\tError case (3) of create failed!\n";




        Art edgeCase(1, 1);
        cout << "\nTesting the edge case of the create function:\n\n";
        if (tester.testCreateNormal(edgeCase) != true)
            cout << "\tEdge case of create passed!\n";
        else
            cout << "\tEdge case of create failed!\n";




        //Test whether the copy constructor works correctly for an edge case, i.e. it copies an empty object correctly.
        cout << "\nTesting the copy constructor for copying an empty object:\n\n";
        defaultArt = edgeCase;
        if (tester.testCopy(defaultArt, edgeCase) == true) {
            cout << "\tCopied empty object correctly\n";
            cout << "\nDump of the copy object:\n\n";
            defaultArt.dumpColors("\u2588");
            cout << "\nDump of the original object:\n\n";
            defaultArt.dumpValues();
        }
        else
            cout << "\tCopied empty object incorrectly\n";



        //Test whether the assignment operator works correctly for a normal case.
        defaultArt = art;
        cout << "\nTesting the assignment operator for a normal case:\n\n";
        if (tester.testCopy(defaultArt, art) == true &&
            tester.testAddress(defaultArt, art) != true) {
            cout << "\tAssignment operator for normal case passed!\n";
            cout << "\nDump of the copy object:\n\n";
            defaultArt.dumpColors("\u2588");
            defaultArt.dumpValues();
            cout << "\nDump of the original object:\n\n";
            art.dumpColors("\u2588");
            art.dumpValues();

        }
        else
            cout << "\tAssignment operator for normal case failed!\n";

//Test whether the assignment operator works correctly for an edge case, i.e. it assigns an empty object correctly.
        cout << "\nTesting the assignment operator works correctly for an edge case, i.e. " <<
                "it assigns an empty object correctly:\n\n";
        defaultArt = edgeCase;
        if (tester.testCopy(defaultArt, edgeCase) == true &&
            tester.testCreateNormal(defaultArt) != true) {
            cout << "\tAssignment operator for edge case passed!\n";
        }
        else
            cout << "\tAssignment operator for edge case failed!\n";

//Test whether left2Right(...) is working correctly for an error case, i.e. two objects have different heights.
//Test whether left2Right(...) is working correctly for appending a normal object to an empty object.
//Test whether left2Right(...) is working correctly for appending an empty object to a normal object.
//Test whether left2Right(...) is working correctly for appending an object to itself.


        //Test whether left2Right(...) is working correctly for a normal case, i.e. appending two normal objects.
        cout << "\nTesting whether left2Right(...) is working correctly for a normal case:\n\n";
        Art left(5, 5);
        Art right(5, 5);

        left.create(10);
        right.create(10);

        copy = left;

        if (tester.testLeft2Right(left, right) == true) {
            cout << "\tleft2Right(...) works correctly for normal case!\n";
            cout << "\nDump of the result of left2Right(..):\n\n";
            left.left2Right(right);
            left.dumpColors("\u2588");
            cout << "\nDump of the original left:\n\n";
            copy.dumpColors("\u2588");
            cout << "\nDump of the original right:\n\n";
            right.dumpColors("\u2588");

        }
        else
            cout << "\tleft2Right(...) not working correctly for normal case!\n";

        Art left1(5,10);
        Art right1(5,5);

        if (tester.testLeft2Right(left, right) != true) {
            cout << "\tleft2Right(...) works correctly for error case!\n";
        }
        else
            cout << "\tleft2Right() not working correctly for error case!\n";

    }

    cout << endl;
    return 0;
}

// [1]
bool Tester::testCreateNormal(Art & art){
    // this function assumes the art object is not empty
    // all color codes must be within the correct range
    bool result = true;
    art.create(10);
    if (art.m_height > 0 && art.m_width > 0 && art.m_painting != nullptr){
        for (int i=0; i < art.m_height; i++){
            for (int j=0; j < art.m_width; j++){
                if(art.m_painting[i][j] < 10 ||
                    art.m_painting[i][j] > 99)
                    result = false;
            }
        }
    }
    else{
        result = false;
        cout << "\tA proper object is not passed to testCreateNormal()\n";
    }
    return result;
}

// [2]
bool Tester::testDefault(Art & art) {
    bool result = true;

    if (art.m_height != 0 && art.m_width != 0 && art.m_painting != nullptr) {
        result = false;
    }
    else {result = true;}

    return result;
}

// [3]
bool Tester::testCopy(const Art & copy, const Art & original) {
    bool result = true;

    // check if the copy is not empty
    if (copy.m_painting != nullptr && original.m_painting != nullptr) {
        if (copy.m_height == original.m_height && copy.m_width == original.m_width) {
            for (int i=0; i< copy.m_height; i++) {
                for (int j=0; j < copy.m_width; j++) {
                    if (copy.m_painting[i][j] != original.m_painting[i][j]) {
                        result = false;
                    }
                }
            }
        }
        // copy height & width do not match the original
        else
            result = false;
    }
    // the original and the copy are both empty
    else if (copy.m_painting == nullptr && original.m_painting == nullptr &&
        copy.m_height == 0 && original.m_height == 0 &&
        copy.m_width == 0 && original.m_width == 0) { }
    // copy is empty
    else
        result = false;


    return result;
}

// create an empty object
// does height = 0 width = 0 and painting == nullptr
// pass otherwise fail
// test default constructor

// test the constructor
// helper function bool isEmpty() if height width = 0 and painting = nullptr
// Art art(-1, 10)
// (-1, 10)
// (-1. -1)...

// m_painting != rhs
// but 2D for loop and check the values are the same
// different memory address
// int**

// check dimension
// check if dimensions match and painting != nullptr

//clear -> isEmpty();

// tests the create() function
bool Tester::testCreateNegative(Art & art) {

    bool result = true;
    art.create(10);

    if (art.m_height == 0 && art.m_width == 0 && art.m_painting == nullptr) {

    }
    else {
        result = false;
        cout << "\tA negative object was created and passed to testCreateNegative()\n";
    }
    return result;
}

bool Tester::testCreateEdgeCase(Art & art) {

    bool result = true;
    art.create(10);

    if (art.m_height == 1 && art.m_width == 1 && art.m_painting != nullptr) {
        for (int i=0; i < art.m_height; i++){
            for (int j=0; j < art.m_width; j++){
                if(art.m_painting[i][j] < 10 ||
                    art.m_painting[i][j] > 99)
                    result = false;
            }
        }
    }
    else{
        result = false;
        cout << "\tA proper object is not passed to testCreateNormal()\n";
    }
    return result;
}

bool Tester::testAddress(const Art & copy, const Art & original) {
    return &copy == &original;
}

bool Tester::testLeft2Right(Art & left, Art & right) {
    bool result = true;

    Art copy = left;

    if (left.m_painting == nullptr && right.m_painting == nullptr) {
        if (left.m_height != right.m_height ||
            left.m_width != right.m_width)
            result = false;

        else {
            left.left2Right(right);

            for (int i=0; i<copy.m_height; i++) {
                for (int j=0; j < copy.m_width; j++) {
                    if (left.m_painting[i][j] != copy.m_painting[i][j]) {
                        result = false;
                    }
                }
            }
            for (int i=0;i<right.m_height;i++) {
                for (int j=0; j < right.m_width; j++) {
                    if (left.m_painting[i][j+right.m_width] != right.m_painting[i][j])
                        result = false;

                }
            }
        }

    }

    return result;
}



