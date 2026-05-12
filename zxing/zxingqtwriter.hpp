#pragma once
#include <QImage>
#include "BarcodeFormat.h"
#ifdef ZXING_EXPERIMENTAL_API
#include "WriteBarcode.h"
#else
#include "BitMatrix.h"
#include "MultiFormatWriter.h"
#endif

namespace ZXingQt {

	QImage WriteBarcode(QStringView text, ZXing::BarcodeFormat format)
	{
		using namespace ZXing;

#ifdef ZXING_EXPERIMENTAL_API
		auto barcode = CreateBarcodeFromText(text.toString().toStdString(), format);
		auto bitmap = WriteBarcodeToImage(barcode);
#else
		auto writer = MultiFormatWriter(format);
		auto matrix = writer.encode(text.toString().toStdString(), 0, 0);
		auto bitmap = ToMatrix<uint8_t>(matrix);
#endif
		return QImage(bitmap.data(), bitmap.width(), bitmap.height(), bitmap.width(), QImage::Format::Format_Grayscale8).copy();
	}



}