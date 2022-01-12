/**********************************************************************************/
/* This file is part of spla project                                              */
/* https://github.com/JetBrains-Research/spla-bench                               */
/**********************************************************************************/
/* MIT License                                                                    */
/*                                                                                */
/* Copyright (c) 2021 JetBrains-Research                                          */
/*                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy   */
/* of this software and associated documentation files (the "Software"), to deal  */
/* in the Software without restriction, including without limitation the rights   */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      */
/* copies of the Software, and to permit persons to whom the Software is          */
/* furnished to do so, subject to the following conditions:                       */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/* copies or substantial portions of the Software.                                */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/**********************************************************************************/

#ifndef SPLA_BENCH_BENCHMARKENGINE_HPP
#define SPLA_BENCH_BENCHMARKENGINE_HPP

#include <memory>
#include <unordered_map>
#include <vector>

namespace bench {

    class BenchmarkEngine {
    public:
        /** Run benchmarks with specified args */
        static int Run(int argc, const char *const *argv);

        /** Register new plugin tool for benchmarking */
        static void Register(const std::shared_ptr<class Plugin> &plugin);

    private:
        static BenchmarkEngine &Instance();

    private:
        BenchmarkEngine() = default;
        ~BenchmarkEngine() = default;

        void Parse(int argc, const char *const *argv);
        int Execute();

    private:
        std::vector<std::string> mOptions;
        std::unordered_map<std::string, std::shared_ptr<Plugin>> mPlugins;
    };

}// namespace bench

#endif//SPLA_BENCH_BENCHMARKENGINE_HPP
