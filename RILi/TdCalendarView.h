//
//  CalendarView.h
//  RILi
//
//  Created by Zin_戦 on 16/6/1.
//  Copyright © 2016年 Zin戦壕. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CalendarViewDelegate;

@interface TdCalendarView : UIView {
	CFGregorianDate currentMonthDate;
	CFGregorianDate currentSelectDate;
	CFAbsoluteTime	currentTime;
	UIImageView* viewImageView;
	 __weak id<CalendarViewDelegate>  calendarViewDelegate;
	int *monthFlagArray; 
}

@property CFGregorianDate currentMonthDate;
@property CFGregorianDate currentSelectDate;
@property CFAbsoluteTime  currentTime;

@property (nonatomic, strong) UIImageView* viewImageView;
@property (nonatomic, weak) id<CalendarViewDelegate> calendarViewDelegate;
-(int)getDayCountOfaMonth:(CFGregorianDate)date;
-(int)getMonthWeekday:(CFGregorianDate)date;
-(int)getDayFlag:(int)day;
-(void)setDayFlag:(int)day flag:(int)flag;
-(void)clearAllDayFlag;
@end



@protocol CalendarViewDelegate<NSObject>
@optional
- (void) selectDateChanged:(CFGregorianDate) selectDate;
- (void) monthChanged:(CFGregorianDate) currentMonth viewLeftTop:(CGPoint)viewLeftTop height:(float)height;
- (void) beforeMonthChange:(TdCalendarView*) calendarView willto:(CFGregorianDate) currentMonth;
@end