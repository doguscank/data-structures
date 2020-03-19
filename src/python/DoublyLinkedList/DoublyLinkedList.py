class Node():
	def __init__(self, data, prev_node, next_node):
		self.data = data #Node data
		self.prev_node = prev_node #Previous node
		self.next_node = next_node #Next node

class DoublyLinkedListInt():
	def __init__(self):
		self.size = 0
		self.head = None #First node
		self.tail = None #Last node

	def size(self):
		return self.size

	def is_empty(self):
		return self.size == 0

	def add(self, data):
		self.add_last(data)

	def add_last(self, data):
		new_node = Node(data, self.tail, None)

		if self.is_empty():
			self.head = new_node
			self.tail = new_node
		else:
			self.tail.next_node = new_node
			self.tail = new_node

		self.size += 1

	def add_first(self, data):
		new_node = Node(data, None, self.head)

		if self.is_empty():
			self.head = new_node
			self.tail = new_node
		else:
			self.head.prev_node = new_node
			self.head = new_node

		self.size += 1

	def remove(self, data):
		if self.is_empty():
			raise Exception('Empty list!')

		index = self.index_of(data)

		if index == -1:
			raise Exception('Can not find any node with given data!')
		self.remove_at(index)

	def remove_at(self, index):
		if self.is_empty():
			raise Exception('Empty list!')

		if index < 0:
			raise Exception('Invalid index!')

		trav = self.head

		if index == 0:
			try:
				trav.next_node.prev_node = None
			except:
				pass

			self.head = trav.next_node
			self.size -= 1
			return

		for i in range(self.size):
			if i == index:
				trav.prev_node.next_node = trav.next_node
				
				try:
					trav.next_node.prev_node = trav.prev_node
				except:
					pass

			else:
				trav = trav.next_node

		self.size -= 1

	def remove_head(self):
		if self.is_empty():
			raise Exception('Empty list!')

		self.remove_at(0)

	def remove_tail(self):
		if self.is_empty():
			raise Exception('Empty list!')

		self.remove_at(self.size - 1)

	def clear(self):
		trav = self.head #Pointer node

		while trav is not None:
			_next = trav.next_node #Save reference of pointer node
			trav.prev_node = None
			trav.next_node = None
			trav.data = None
			trav = _next #Move to the next node

		self.head = None
		self.tail = None
		self.size = 0

	def index_of(self, data):
		trav = self.head
		index = 0

		while trav is not None:
			if trav.data == data:
				return index
			trav = trav.next_node
			index += 1

		return -1

	def peek_first(self):
		if self.head is None:
			raise Exception('There are no nodes in the list!')
		return self.head.data

	def peek_last(self):
		if self.head is None:
			raise Exception('There are no nodes in the list!')
		return self.tail.data

	def contains(self, data):
		return self.index_of(data) != -1

	def to_string(self):
		seperator = ", "
		str_list = []

		trav = self.head

		while trav is not None:
			str_list.append(trav.data)
			trav = trav.next_node

		return seperator.join(str(i) for i in str_list)

if __name__ == '__main__':
	dll = DoublyLinkedListInt()
	dll.add(1)	
	dll.add(2)
	dll.add(3)
	dll.add(4)
	dll.add(5)
	print(dll.to_string())
	dll.remove_head()
	print(dll.to_string())
	dll.remove_tail()
	print(dll.to_string())
	#print(dll.index_of(3))
	dll.remove_at(0)
	print(dll.to_string())
	#print(dll.contains(4))