#pragma once

namespace vm { using namespace ps3; }

// Error Codes
enum
{
	CELL_JPGENC_ERROR_ARG   = 0x80611191,
	CELL_JPGENC_ERROR_SEQ   = 0x80611192,
	CELL_JPGENC_ERROR_BUSY  = 0x80611193,
	CELL_JPGENC_ERROR_EMPTY = 0x80611194,
	CELL_JPGENC_ERROR_RESET = 0x80611195,
	CELL_JPGENC_ERROR_FATAL = 0x80611196,
	
	CELL_JPGENC_ERROR_STREAM_ABORT = 0x806111A1,
	CELL_JPGENC_ERROR_STREAM_SKIP = 0x806111A2,
	CELL_JPGENC_ERROR_STREAM_OVERFLOW = 0x806111A3,
	CELL_JPGENC_ERROR_STREAM_FILE_OPEN = 0x806111A4,
};

// Definitions
enum
{
	CELL_JPGENC_COLOR_SPACE_GRAYSCALE = 1,
	CELL_JPGENC_COLOR_SPACE_RGB = 2,
	CELL_JPGENC_COLOR_SPACE_YCbCr = 3,
	CELL_JPGENC_COLOR_SPACE_RGBA = 10,
	CELL_JPGENC_COLOR_SPACE_ARGB = 20,
	
	CELL_JPGENC_SAMPLING_FMT_YCbCr444,
	CELL_JPGENC_SAMPLING_FMT_YCbCr422,
	CELL_JPGENC_SAMPLING_FMT_YCbCr420,
	CELL_JPGENC_SAMPLING_FMT_YCbCr411,
	CELL_JPGENC_SAMPLING_FMT_FULL,
	
	CELL_JPGENC_DCT_METHOD_QUALITY = 0,
	CELL_JPGENC_DCT_METHOD_FAST = 5,
	
	CELL_JPGENC_COMPR_MODE_CONSTANT_QUALITY,
	CELL_JPGENC_COMPR_MODE_STREAM_SIZE_LIMIT,
	
	CELL_JPGENC_LOCATION_FILE,
	CELL_JPGENC_LOCATION_BUFFER,
};
