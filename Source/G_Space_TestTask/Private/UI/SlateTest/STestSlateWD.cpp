// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SlateTest/STestSlateWD.h"

static const float Thickness = 10.f;


void STestSlateWD::Construct(const FArguments& InArgs)
{
	SetOnMouseMove(FPointerEventHandler::CreateLambda([this](const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) -> FReply
		{
			auto LocalPosition = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());

			float CurveY = 300.f + 100 * FMath::Sin(LocalPosition.X / 50.f);

			bool bMoveOnCurve = LocalPosition.Y > CurveY - Thickness / 2 && LocalPosition.Y < CurveY + Thickness / 2;

			if (bMoveOnCurve)
			{
				if (LocalPosition.X < 500.f)
				{
					GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, TEXT("part1"));
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, TEXT("part2"));
				}
			}

			return FReply::Handled();
		}));
}

int32 STestSlateWD::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
                            FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
                            bool bParentEnabled) const
{
	auto LabelBrush = FAppStyle::GetBrush(TEXT("BlendSpaceEditor.LabelBackground"));

	//part1
	TArray<FVector2f> Points;
	for (int32 i = 0; i < 50; i++)
	{
		Points.Add(FVector2f(i * 10.f, 300.f + 100 * FMath::Sin(i / 5.f)));
	}
	FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), Points, ESlateDrawEffect::None, FColor::Red, true, Thickness);

	//part2
	Points.Reset();
	for (int32 i = 49; i < 100; i++)
	{
		Points.Add(FVector2f(i * 10.f, 300.f + 100 * FMath::Sin(i / 5.f)));
	}
	FSlateDrawElement::MakeLines(OutDrawElements, LayerId, AllottedGeometry.ToPaintGeometry(), Points, ESlateDrawEffect::None, FColor::Green, true, Thickness);

	return LayerId;
}

FVector2D STestSlateWD::ComputeDesiredSize(float) const
{
	return FVector2D(500.f, 500.f);
}
