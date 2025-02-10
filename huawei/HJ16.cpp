// 购物单

#include <iostream>
#include <vector>

using std::max;
using std::vector;

#define MAIN_ITEM 0
#define SCALE 10

struct Attachment
{
    Attachment(int price, int importance, int main_item)
        : price_(price), importance_(importance), main_item_(main_item)
    {
        satis_ = price_ * importance_;
    }
    int price_;
    int importance_;
    int main_item_;
    int satis_;
};

struct Item
{
    Item(int price, int importance, int index)
        : price_(price), importance_(importance), index_(index)
    {
        satis_ = price_ * importance_;
    }
    int                     price_;
    int                     importance_;
    int                     index_;
    int                     satis_;
    std::vector<Attachment> atts_;
};

int main()
{
    int budget_cap;
    int input_line_amount;
    std::cin >> budget_cap >> input_line_amount;

    std::vector<Item>       items;
    std::vector<Attachment> attachments;

    for (int i = 0; i < input_line_amount; i++)
    {
        int price;
        int importance;
        int main_item;
        std::cin >> price >> importance >> main_item;
        if (main_item == MAIN_ITEM)
            items.push_back(Item{price / SCALE, importance, i});
        else
            attachments.push_back(
                Attachment{price / SCALE, importance, main_item});
    }

    for (const auto& attachment : attachments)
    {
        for (auto& item : items)
        {
            if (item.index_ + 1 == attachment.main_item_)
                item.atts_.push_back(attachment);
        }
    }

    budget_cap /= SCALE;
    vector<vector<int>> satis(items.size() + 1, vector<int>(budget_cap + 1, 0));
    for (int i = 1; i < items.size() + 1; ++i)
    {
        const Item& item = items[i - 1];
        for (int budget = 1; budget < budget_cap + 1; ++budget)
        {
            // Option 0: Do not but this item
            satis[i][budget] = satis[i - 1][budget];

            // Option 1: But the main item alone
            if (item.price_ <= budget)
            {
                satis[i][budget] = max(satis[i][budget],
                                       satis[i - 1][budget - item.price_]
                                           + item.satis_);
            }

            // Option 2: Buy the main item and first attachment (if exists)
            if (item.atts_.size() >= 1
                && item.price_ + item.atts_[0].price_ <= budget)
            {
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i - 1][budget - item.price_ - item.atts_[0].price_]
                        + item.satis_ + item.atts_[0].satis_);
            }

            // Option 3: Buy the main item and second attachment (if exists)
            if (item.atts_.size() >= 2
                && item.price_ + item.atts_[1].price_ <= budget)
            {
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i - 1][budget - item.price_ - item.atts_[1].price_]
                        + item.satis_ + item.atts_[1].satis_);
            }

            // Option 4: Buy the main item with both attachments (if exist)
            if (item.atts_.size() >= 2
                && item.price_ + item.atts_[0].price_ + item.atts_[1].price_
                       <= budget)
            {
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i - 1][budget - item.price_ - item.atts_[0].price_
                                 - item.atts_[1].price_]
                        + item.satis_ + item.atts_[0].satis_
                        + item.atts_[1].satis_);
            }
        }
    }
    std::cout << satis[items.size()][budget_cap] * SCALE << "\n";
}
