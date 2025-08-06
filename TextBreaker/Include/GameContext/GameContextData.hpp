#ifndef TEXT_GAME_ENGINE_GAME_CONTEXT_HEADER
#define TEXT_GAME_ENGINE_GAME_CONTEXT_HEADER

#include <string>

namespace TextGameEngine
{
    namespace GameContext
    {
        class GameContextData
        {
        private:
            std::string _nowSceneName = "";
            double _frameTimeInterval;
            double _fixedTimeInterval;
            double _deltaTime=0;
            double _totalDeltaTime=0;
            double _accumulatedFixedTime = 0;
            int _targetFPS;
        public:
            GameContextData(double fixedTimeInterval, int targetFPS);

            void SetNowSceneName(const std::string& name);
            const std::string& GetNowSceneName() const;

            double GetFrameTimeInterval() const;
            double GetFixedTimeInterval() const;

            double GetDeltaTime() const;
            void SetDeltaTime(double time);

            double GetTotalDeltaTime() const;
            void AddTotalDeltaTime(double time);

            double GetAccumulatedFixedTime() const;
            void AddAccumulatedFixedTime(double time);
            void SubAccumulatedFixedUpdate();

            int GetTargetFPS() const;
        };
    }
}

#endif // !TEXT_GAME_ENGINE_GAME_CONTEXT_HEADER
