"""Linked List implementation"""
from typing import Optional


class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next : Optional[Node]= None

class LinkedList:
    """
    We implement the following List methods:
    - insert
    - Search
    - delete
    """
    def __init__(self) -> None:
        self.head: Optional[Node] = None

    def insert(self, node: Node) -> None:
        """
        Always insert at head to ensure O(1) time
        """
        if self.head is None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def search(self, data: int) -> bool:
        """
        Search for data in the List
        """
        current = self.head
        while current:
            if current.data == data:
                return True
            current = current.next
        return False

    def delete(self, data: int) -> None:
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next is not None:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def __str__(self) -> str:
        elements: list[str] = []
        current = self.head
        while current != None:
            elements.append(str(current.data))
            current = current.next
        return " -> ".join(elements)

if __name__ == '__main__':
    linked_list = LinkedList()
    for i in range(1, 6):
        node = Node(i)
        if linked_list.head is None:
            linked_list.head = node
        else:
            linked_list.insert(node)

    print(linked_list)
    print(f"Do we have 4 in the list ?{linked_list.search(4)=}")
    print(f"Do we have 10 i0 the list ?{linked_list.search(10)=}")
    linked_list.delete(4)
    print("After delete(4)")
    print(linked_list)
