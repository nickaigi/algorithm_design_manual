"""Linked List implementaiton"""


class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def search_list(self, curr: Node,  data: int):
        """
        Search for data in the List
        """
        if curr is None:
            return

        if curr.data == data:
            return curr
        return self.search_list(curr, data)

    def insert(self, node: Node):
        """
        Always insert at head to ensure O(1) time
        """
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def __str__(self) -> str:
        values: list[str] = []
        curr = self.head
        while curr != None:
            values.append(f"{curr.data}")
            curr = curr.next
        return " -> ".join(values)

if __name__ == '__main__':
    linked_list = LinkedList()
    for i in range(1, 6):
        node = Node(i)
        if linked_list.head is None:
            linked_list.head = node
        else:
            linked_list.insert(node)

    print(linked_list)
