from typing import List

SCALE = 10

class Att:
    price: int
    satis: int
    main_item_index: int
    def __init__(self, price: int, importance: int, main_item_index: int):
        self.price = price // SCALE
        self.satis = price * importance
        self.main_item_index = main_item_index


class Item:
    price: int
    satis: int
    index: int
    atts: List[Att]
    def __init__(self, price: int, importance: int, index: int):
        self.price = price // SCALE
        self.satis = price * importance
        self.index = index
        self.atts = []


def main():
    total_budget, input_lines = map(int, input().split(' '))
    items: List[Item] = []
    atts: List[Att] = []
    for index in range(input_lines):
        price, importance, main_item_number = map(int, input().split(' '))
        if main_item_number == 0:
            items.append(Item(price, importance, index))
        else:
            atts.append(Att(price, importance, main_item_number - 1))

    for att in atts:
        for item in items:
            if att.main_item_index == item.index:
                item.atts.append(att)
                break


    total_budget //= SCALE
    satis = [[0 for _ in range(total_budget + 1)] for _ in range (len(items)+1)]
    for i in range(1, len(items) + 1):
        item = items[i-1]
        for budget in range(1, total_budget + 1):
            # Option 0: Do not buy item
            satis[i][budget] = satis[i-1][budget]
            # Option 1: Buy item alone
            if item.price <= budget:
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i-1][budget-item.price] + item.satis
                )
            # Option 2: Buy item with first attachment
            if len(item.atts) >= 1 \
                and item.atts[0].price + item.price <= budget:
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i-1][budget-item.price-item.atts[0].price] \
                        + item.satis + item.atts[0].satis
                )
            # Option 3: Buy item with second attachment
            if len(item.atts) >= 2 \
                and item.atts[1].price + item.price <= budget:
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i-1][budget-item.price-item.atts[1].price] \
                        + item.satis + item.atts[1].satis
                )
            # Option 4: Buy item with with both attachments
            if len(item.atts) >= 2 \
                and item.atts[0].price + item.atts[1].price + item.price \
                    <= budget:
                satis[i][budget] = max(
                    satis[i][budget],
                    satis[i-1][budget-item.price-item.atts[0].price-item.atts[1].price] \
                        + item.satis + item.atts[0].satis + item.atts[1].satis
                )

    print(satis[-1][-1])

if __name__ == "__main__":
    main()

