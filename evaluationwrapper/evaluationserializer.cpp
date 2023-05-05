#include "evaluationserializer.h"
#include <json/json.h>


std::string serializeEvaluationRequest(const WordDetail &detial, std::vector<UStroke> &strokes,
                                       std::string mac, int classId, bool isWorkClass,
                                       std::string imgKey, std::string imgPath, std::string jsonKey,
                                       std::string jsonPath) {
    return "";
}

int unserializeEvaluationRequest(const std::string &data, EvaluationRequest &request)
{
    return -1;
}

std::string serializeEvaluationResponse(std::string mac, std::string imgKey, std::string imgPath, std::string jsonKey, std::string jsonPath, std::string evaluateResult)
{
    return "";
}

int unserializeEvaluationResponse(const std::string &data, EvaluationResponse &response)
{
    return -1;
}

