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

#include <slim/log/SinkFilter.hpp>
#include <algorithm>



// TODO: use from Message
std::string rightTrim(const std::string &s) {
	auto r = std::find_if_not(s.rbegin(), s.rend(), [](int c) {
		return std::isspace(c);
	}).base();

	return std::string(s.begin(), r);
}


SinkFilter::SinkFilter(std::function<bool(g3::LogMessage&)> filter) :
	_filter(filter) {
}


SinkFilter::~SinkFilter() {
}


bool SinkFilter::filter(g3::LogMessage& logMessage) {
	return (_filter && _filter(logMessage));
}
