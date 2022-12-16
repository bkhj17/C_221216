#pragma once

#include <iostream>
#include <string>

#include <vector>

//키 값에 사용자 정의 자료형이 들어갈 경우 비교 함수 필요
#include <map>	//정렬 있음. 자료가 적으면 검색속도 빨라짐
#include <unordered_map> //정렬 없음. 자료가 많아도 검색 속도는 같음

#include <algorithm>
using namespace std;

#include "Item.h"
#include "DoublyNode.h"
#include "DoublyLinkedList.h"

#include "DataManager.h"

#include "Store.h"