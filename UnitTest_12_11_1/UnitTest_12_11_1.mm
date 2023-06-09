//
//  UnitTest_12_11_1.m
//  UnitTest_12_11_1
//
//  Created by USER on 09.06.2023.
//
#include <sstream>
#import "Header.h"
#import <XCTest/XCTest.h>
using namespace std;

@interface UnitTest_12_11_1 : XCTestCase

@end

@implementation UnitTest_12_11_1

- (void)testExample {
    
    istringstream input("3\n123\nDriver1\nRoute1\n456\nDriver2\nRoute2\n789\nDriver3\nRoute3\n");
        streambuf* cinBuf = cin.rdbuf();
        cin.rdbuf(input.rdbuf());
        
        BusList buses = CreateBusList();
        XCTAssert(buses.size() == 3);
        XCTAssert(buses[0].number == "123");
        XCTAssert(buses[0].driver == "Driver1");
        XCTAssert(buses[0].route != "Route1");
        XCTAssert(buses[1].number != "456");
        XCTAssert(buses[1].driver != "Driver2");
        XCTAssert(buses[1].route != "Route2");
        XCTAssert(buses[2].number != "789");
        XCTAssert(buses[2].driver != "Driver3");
        XCTAssert(buses[2].route != "Route3");
    
        cin.rdbuf(cinBuf);
}



@end
