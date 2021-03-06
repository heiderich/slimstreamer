/*
 * Copyright 2017, Andrej Kislovskij
 *
 * This is PUBLIC DOMAIN software so use at your own risk as it comes
 * with no warranties. This code is yours to share, use and modify without
 * any restrictions or obligations.
 *
 * For more information see conwrap/LICENSE or refer refer to http://unlicense.org
 *
 * Author: gimesketvirtadieni at gmail dot com (Andrej Kislovskij)
 */

#pragma once

#include <cstdint>  // std::int..._t
#include <iostream>
#include <memory>


namespace slim
{
	namespace wave
	{
		class WAVEStream
		{
			public:
				explicit WAVEStream(std::unique_ptr<std::ostream> os, unsigned int c, unsigned int s, unsigned int b)
				: outputStreamPtr{std::move(os)}
				, channels{c}
				, sampleRate{s}
				, bitsPerSample{b}
				, bytesPerFrame{channels * (bitsPerSample >> 3)}
				, byteRate{sampleRate * bytesPerFrame} {}

				// using Rule Of Zero
			   ~WAVEStream() = default;
				WAVEStream(const WAVEStream&) = delete;             // non-copyable
				WAVEStream& operator=(const WAVEStream&) = delete;  // non-assignable
				WAVEStream(WAVEStream&&) = default;
				WAVEStream& operator=(WAVEStream&&) = default;

				auto& getOutputStream()
				{
					return *outputStreamPtr;
				}

				void write(std::string str);
				void write(const void* buffer, std::size_t size);
				void writeHeader(std::uint32_t size = 0);

			private:
				std::unique_ptr<std::ostream> outputStreamPtr;
				unsigned int                  channels;
				unsigned int                  sampleRate;
				unsigned int                  bitsPerSample;
				unsigned int                  bytesPerFrame;
				unsigned int                  byteRate;
		};
	}
}
