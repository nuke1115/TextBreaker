#include "../../Include/GameContext/GameContextData.hpp"

TextGameEngine::GameContext::GameContextData::GameContextData(double fixedTimeInterval, int targetFPS)
{
    _frameTimeInterval = 1.0 / static_cast<double>(targetFPS);
    _fixedTimeInterval = fixedTimeInterval;
    _targetFPS = targetFPS;
}

void TextGameEngine::GameContext::GameContextData::SetNowSceneName(const std::string& name)
{
    _nowSceneName = name;
}
const std::string& TextGameEngine::GameContext::GameContextData::GetNowSceneName() const
{
    return _nowSceneName;
}

double TextGameEngine::GameContext::GameContextData::GetFrameTimeInterval() const
{
    return _frameTimeInterval;
}
double TextGameEngine::GameContext::GameContextData::GetFixedTimeInterval() const
{
    return _fixedTimeInterval;
}

double TextGameEngine::GameContext::GameContextData::GetDeltaTime() const
{
    return _deltaTime;
}
void TextGameEngine::GameContext::GameContextData::SetDeltaTime(double time)
{
    _deltaTime = time;
}

double TextGameEngine::GameContext::GameContextData::GetTotalDeltaTime() const
{
    return _totalDeltaTime;
}
void TextGameEngine::GameContext::GameContextData::AddTotalDeltaTime(double time)
{
    _totalDeltaTime += time;
}

int TextGameEngine::GameContext::GameContextData::GetTargetFPS() const
{
    return _targetFPS;
}

double TextGameEngine::GameContext::GameContextData::GetAccumulatedFixedTime() const
{
    return _accumulatedFixedTime;
}
void TextGameEngine::GameContext::GameContextData::AddAccumulatedFixedTime(double time)
{
    _accumulatedFixedTime += time;
}

void TextGameEngine::GameContext::GameContextData::SubAccumulatedFixedUpdate()
{
    _accumulatedFixedTime -= _fixedTimeInterval;
}
