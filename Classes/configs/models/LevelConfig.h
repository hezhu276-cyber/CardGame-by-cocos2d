<<<<<<< HEAD
#pragma once #ifndef CONFIGS_MODELS_LEVELCONFIG_H #define CONFIGS_MODELS_LEVELCONFIG_H
#include <vector>
#include <iostream>
#include "cocos2d.h"
#include <string> 

// JSON ���ͷ�ļ�
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "json/filereadstream.h"

// ��Ŀ��ͷ�ļ�
#include "models/CardModel.h"

// ʹ�� rapidjson �����ռ�
using namespace rapidjson;

/**

@class LevelConfig
@brief Level configuration class that holds static level data, including playfield and stack configurations.
@details This class adheres to the MVC architecture's configs layer specifications, functioning solely as a
storage container for static configuration data without containing any business logic.
@note The class is designed to be immutable after initialization, with data population handled exclusively
by the LevelConfigLoader class.
/
class LevelConfig final {
public:
/*
@brief Retrieves the list of cards in the playfield.
@return A copy of the vector containing playfield CardModel objects.
*/
std::vector<CardModel> getPlayfield() {

	std::vector<CardModel> tempPlayfield = _playfieldCards;
	return tempPlayfield;
}
/**
@brief Retrieves the list of cards in the stack.
@return A copy of the vector containing stack CardModel objects.
*/
std::vector<CardModel> getStack() {
	return _stackCards;
}

static const int kDefaultCardCount = 0;

private:
	// �������������ã���Ӧ JSON �е� "Playfield" �ֶ�
	std::vector<CardModel> _playfieldCards;
	// �����ƶ����ã���Ӧ JSON �е� "Stack" �ֶ�
	std::vector<CardModel> _stackCards;

	bool _isValid = true;

	/**

	@brief Private default constructor to prevent direct instantiation.
	Initialization is restricted to the LevelConfigLoader class.
	*/
	LevelConfig() = default;

	/**

	@brief Private destructor.
	Destruction is managed automatically as per object lifecycle.
	*/
	~LevelConfig() = default;

	/**

	@brief Deleted copy constructor to prevent object copying.
	*/
	LevelConfig(const LevelConfig&) = delete;

	/**

	@brief Deleted assignment operator to prevent object assignment.
	*/
	LevelConfig& operator=(const LevelConfig&) = delete;

	/**

	@brief Friend class declaration to allow LevelConfigLoader to populate data.
	This ensures controlled initialization of the configuration data.
	*/
	friend class LevelConfigLoader;
};

=======
#pragma once #ifndef CONFIGS_MODELS_LEVELCONFIG_H #define CONFIGS_MODELS_LEVELCONFIG_H
#include <vector>
#include <iostream>
#include "cocos2d.h"
#include <string> 

// JSON ���ͷ�ļ�
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "json/filereadstream.h"

// ��Ŀ��ͷ�ļ�
#include "models/CardModel.h"

// ʹ�� rapidjson �����ռ�
using namespace rapidjson;

/**

@class LevelConfig
@brief Level configuration class that holds static level data, including playfield and stack configurations.
@details This class adheres to the MVC architecture's configs layer specifications, functioning solely as a
storage container for static configuration data without containing any business logic.
@note The class is designed to be immutable after initialization, with data population handled exclusively
by the LevelConfigLoader class.
/
class LevelConfig final {
public:
/*
@brief Retrieves the list of cards in the playfield.
@return A copy of the vector containing playfield CardModel objects.
*/
std::vector<CardModel> getPlayfield() {

	std::vector<CardModel> tempPlayfield = _playfieldCards;
	return tempPlayfield;
}
/**
@brief Retrieves the list of cards in the stack.
@return A copy of the vector containing stack CardModel objects.
*/
std::vector<CardModel> getStack() {
	return _stackCards;
}

static const int kDefaultCardCount = 0;

private:
	// �������������ã���Ӧ JSON �е� "Playfield" �ֶ�
	std::vector<CardModel> _playfieldCards;
	// �����ƶ����ã���Ӧ JSON �е� "Stack" �ֶ�
	std::vector<CardModel> _stackCards;

	bool _isValid = true;

	/**

	@brief Private default constructor to prevent direct instantiation.
	Initialization is restricted to the LevelConfigLoader class.
	*/
	LevelConfig() = default;

	/**

	@brief Private destructor.
	Destruction is managed automatically as per object lifecycle.
	*/
	~LevelConfig() = default;

	/**

	@brief Deleted copy constructor to prevent object copying.
	*/
	LevelConfig(const LevelConfig&) = delete;

	/**

	@brief Deleted assignment operator to prevent object assignment.
	*/
	LevelConfig& operator=(const LevelConfig&) = delete;

	/**

	@brief Friend class declaration to allow LevelConfigLoader to populate data.
	This ensures controlled initialization of the configuration data.
	*/
	friend class LevelConfigLoader;
};

>>>>>>> c8dc0619d1b49261baf4d4cdb190a8c4fbf38b76
#endif // CONFIGS_MODELS_LEVELCONFIG_H