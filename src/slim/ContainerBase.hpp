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


namespace slim
{
	class ContainerBase
	{
		public:
			ContainerBase()
			: processorProxyPtr{nullptr} {}

			// using Rule Of Zero
			virtual ~ContainerBase() = default;
			ContainerBase(const ContainerBase&) = delete;             // non-copyable
			ContainerBase& operator=(const ContainerBase&) = delete;  // non-assignable
			ContainerBase(ContainerBase&& rhs) = default;
			ContainerBase& operator=(ContainerBase&& rhs) = default;

			virtual void setProcessorProxy(conwrap::ProcessorAsioProxy<ContainerBase>* p)
			{
				processorProxyPtr = p;
			}

			virtual void start() = 0;
			virtual void stop() = 0;

		private:
			conwrap::ProcessorAsioProxy<ContainerBase>* processorProxyPtr;
	};
}
