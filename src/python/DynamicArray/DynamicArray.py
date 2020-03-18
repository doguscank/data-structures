class DynamicArray():
	def __init__(self, capacity):
		if capacity < 0:
			raise Exception('Illegal capacity: {}'.format(capacity))
		else:
			self.capacity = capacity
			self.clear() #Construct empty array

	def size(self):
		return self.capacity

	def is_empty(self):
		return True if self.capacity == 0 else False

	def get(self, index):
		try:
			return self.arr[index]
		except:
			raise Exception('No element found at index {}!'.format(index))

	def set(self, index, elem):
		try:
			self.arr[index] = elem
		except:
			raise Exception('Invalid index: {}'.format(index))

	def clear(self):
		self.arr = [None for i in range(self.capacity)]
		self.length = 0

	def add(self, elem):
		if self.length + 1 >= self.capacity: #If array is going to be fulled, expand capacity before appending new element
			if self.capacity == 0:
				self.capacity = 1
			else:
				self.capacity *= 2

				new_arr = [None for i in range(self.capacity)]

				#Copy elements from old array to new array
				for i in range(self.capacity):
					if i < self.length:
						new_arr[i] = self.arr[i]
				self.arr = new_arr

		self.arr[self.length] = elem #Append new element
		self.length += 1

	def remove_at(self, index):
		if index >= self.length or index < 0:
			raise Exception('Invalid index: {}'.format(index))
		else:
			new_arr = [None for i in range(self.capacity - 1)]

			for i in range(self.length - 1): #Copy elements except removed one
				if i >= index:
					new_arr[i] = self.arr[i + 1]
				else:
					new_arr[i] = self.arr[i]

			self.arr = new_arr

		self.length -= 1

	#Try to remove element if exists
	def remove(self, elem):
		for i in range(self.length):
			if self.arr[i] == elem:
				self.remove_at(i)
				return True				
		return False

	def index_of(self, elem):
		for i in range(self.length):
			if self.arr[i] == elem:
				return i			
		return -1

	def contains(self, elem):
		return self.index_of(elem) != -1

	def to_string(self):
		seperator = ", "
		return seperator.join(str(self.arr[i]) for i in range(self.length))

if __name__ == '__main__':
	arr = DynamicArray(1)
	arr.add(1)
	arr.add(3)
	arr.add(6)
	arr.add(7)
	arr.add(8)
	arr.add(3)
	arr.add(2)
	arr.add(4)
	arr.add(2)
	arr.add(9)
	arr.remove_at(1)
	arr.remove(9)
	arr.set(3, 11)

	print(arr.to_string())