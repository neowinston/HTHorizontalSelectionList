//
//  HTHorizontalSelectionList.h
//  Hightower
//
//  Created by Erik Ackermann on 7/31/14.
//  Copyright (c) 2014 Hightower Inc. All rights reserved.
//

@import UIKit;

@protocol HTHorizontalSelectionListDataSource;
@protocol HTHorizontalSelectionListDelegate;

typedef NS_ENUM(NSInteger, HTHorizontalSelectionIndicatorStyle) {
    HTHorizontalSelectionIndicatorStyleBottomBar,           // Default
    HTHorizontalSelectionIndicatorStyleButtonBorder,
    HTHorizontalSelectionIndicatorStyleNone
};

@interface HTHorizontalSelectionList : UIView

@property (nonatomic) NSInteger selectedButtonIndex;        // returns selected button index. -1 if nothing selected
                                                            // to animate this change, use `-setSelectedButtonIndex:animated:`
                                                            // NOTE: this value will persist between calls to `-reloadData`

@property (nonatomic, weak) id<HTHorizontalSelectionListDataSource> dataSource;
@property (nonatomic, weak) id<HTHorizontalSelectionListDelegate> delegate;

@property (nonatomic, strong) UIColor *selectionIndicatorColor;
@property (nonatomic, strong) UIColor *bottomTrimColor;
@property (nonatomic) BOOL bottomTrimHidden;                // Default is NO
@property (nonatomic) CGFloat fontSize;

@property (nonatomic) UIEdgeInsets buttonInsets;

@property (nonatomic) HTHorizontalSelectionIndicatorStyle selectionIndicatorStyle;

- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;

- (void)reloadData;

- (void)setSelectedButtonIndex:(NSInteger)selectedButtonIndex animated:(BOOL)animated;

@end

@protocol HTHorizontalSelectionListDataSource <NSObject>

- (NSInteger)numberOfItemsInSelectionList:(HTHorizontalSelectionList *)selectionList;

@optional
- (NSString *)selectionList:(HTHorizontalSelectionList *)selectionList titleForItemWithIndex:(NSInteger)index;
- (UIView *)selectionList:(HTHorizontalSelectionList *)selectionList viewForItemWithIndex:(NSInteger)index;

@end

@protocol HTHorizontalSelectionListDelegate <NSObject>

- (void)selectionList:(HTHorizontalSelectionList *)selectionList didSelectButtonWithIndex:(NSInteger)index;

@end
