#pragma once

#include <array>
#include <thread>

// Inject brofiler code into the task scope
#define MT_SCHEDULER_PROFILER_TASK_SCOPE_CODE_INJECTION( TYPE, DEBUG_COLOR, SRC_FILE, SRC_LINE) BROFILER_CATEGORY( MT_TEXT( #TYPE ), DEBUG_COLOR );

#if !defined(BRO_ENABLE_FIBERS)
#define BRO_ENABLE_FIBERS (0)
#endif

#if BRO_ENABLE_FILBERS
#include <MTScheduler.h>
#endif //BRO_ENABLE_FILBERS

namespace Test
{
	// Test engine: emulates some hard CPU work.
	class Engine
	{
#if BRO_ENABLE_FILBERS
		MT::TaskScheduler scheduler;
#endif //BRO_ENABLE_FILBERS
        
		static const size_t WORKER_THREAD_COUNT = 2;
        std::array<std::thread, WORKER_THREAD_COUNT> workers;
		bool isAlive;

		void UpdateInput();
		void UpdateMessages();
		void UpdateLogic();
		void UpdateTasks();
		void UpdateScene();
		void Draw();
	public:
		Engine();
		~Engine();

		// Updates engine, should be called once per frame.
		// Returns false if it doesn't want to update any more.
		bool Update();

		void UpdatePhysics();
		void UpdateRecursive();

		bool IsAlive() const { return isAlive; }
	};
}
