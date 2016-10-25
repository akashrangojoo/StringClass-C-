#include "/home/cs689/progs/p11/String.h"

// This driver program is used to test the user-defined String
// class and its friend and member functions for several possible
// input values.

int main ( )
{
    // test assign ( ) member function

    String str;
    String base = "The quick brown fox jumps over a lazy dog.";

    str.assign ( base ); cout << str << endl;
    str.assign ( base, 10, 9 ); cout << str << endl;
    str.assign ( "pangrams are cool", 7 ); cout << str << endl;
    str.assign ( "c-string"  ); cout << str << endl;
    str.assign ( 10, '*' ); cout << str << endl;
    str.assign ( 10, 0x2D ); cout << str << endl;
    str.assign ( base, 16, base.length ( ) - 28 );
    cout << str << endl << endl;

    // test append ( ) member function

    str = "";
    String str2 = "Writing ";
    String str3 = "print 10 and then 5 more";

    str.append ( str2 ); cout << str << endl;
    str.append ( str3, 6, 3 ); cout << str << endl;
    str.append ( "dots are cool", 5 ); cout << str << endl;
    str.append ( "here: " ); cout << str << endl;
    str.append ( 10, '.' ); cout << str << endl;
    str.append ( str3, 8, str3.length ( ) ); cout << str << endl;
    str.append ( 5, 0x2E ); cout << str << endl << endl;

    // test compare ( ) member function

    String str1 ( "green apple" ); str2 = "red apple";

    if ( str1.compare ( str2 ) )
        cout << str1 << " is not " << str2 << endl;
    if ( !str1.compare ( 6, 5, "apple" ) )
        cout << "still, " << str1 << " is an apple\n";
    if ( !str2.compare ( str2.size ( ) -5, 5, "apple" ) )
        cout << "and " << str2 << " is also an apple\n";
    if ( !str1.compare ( 6, 5, str2, 4, 5 ) )
        cout << "therefore, both are apples\n\n";

    // test insert ( ) member function

    str = "to be question", str2 = "the ",
    str3 = "or not to be";

    str.insert ( 6, str2 ); cout << str << endl;
    str.insert ( 6, str3, 3, 4 ); cout << str << endl;
    str.insert ( 10, "that is cool", 8 ); cout << str << endl;
    str.insert ( 10, "to be " ); cout << str << endl;
    str.insert ( 15, 1, ':' ); cout << str << endl;
    str.insert ( 5, 1, ',' ); cout << str << endl;
    str.insert ( str.length ( ), 3, '.' ); cout << str << endl;
    cout << endl;

    // test erase ( ) and clear ( ) member functions

    str = String ( "This is an example sentence." );
    cout << str << endl;

    str.erase ( 10, 8 ); cout << str << endl;
    str.erase ( 9, 1 ); cout << str << endl;
    str.erase ( 5, str.length ( ) - 14 );
    cout << str << endl << endl;;

    char c;
    str.clear ( );
    cout << "Please type some lines of text. "
         << "Enter a dot (.) to finish:\n\n";

    do {
        c = cin.get ( ); str += c;
        if ( c == '\n' ) { cout << str; str.clear ( ); }
    } while ( c != '.' );
    cout << endl;

    // test replace ( ) member function

    base = "this is a test string.";
    str2 = "n example"; str3 = "sample phrase";
    String str4 = "useful.";

    str = base; cout << str << endl;
    str.replace ( 9, 5, str2 ); cout << str << endl;
    str.replace ( 19, 6, str3, 7, 6 ); cout << str << endl;
    str.replace ( 8, 10, "just a" ); cout << str << endl;
    str.replace ( 8, 6, "a shorty", 7 ); cout << str << endl;
    str.replace ( 22, 1, 3, '!' ); cout << str << endl << endl;

    str.replace ( 0, str.length ( ) - 3, str3 ); cout << str << endl;
    str.replace ( 0, 6, "replace" ); cout << str << endl;
    str.replace ( 8, 6, "is coolness", 7 ); cout << str << endl;
    str.replace ( 12, str.length ( ) - 16, 4, 'o'); cout << str << endl;
    str.replace ( 11, str.length ( ) - 11, str4, 0,  str4.length ( ) );
    cout << str << endl << endl;

    // test copy ( ) member function

    const size_t bufSize = 20; char buffer [ bufSize ];
    str = String ( "Test string..." );

    size_t len = str.copy ( buffer, 6, 5 ); buffer [ len ] = 0;
    cout << "buffer contains: " << buffer << endl << endl;

    // test swap ( ) member function

    String buyer ( "money" ), seller ( "goods" );
    cout << "Before the swap, buyer has " << buyer
         << " and seller has " << seller << ".\n";

    seller.swap ( buyer );
    cout << "After the swap, buyer has " << buyer
         << " and seller has " << seller << ".\n";

    return 0;
}
