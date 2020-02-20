using namespace std;

class Matrix {

	int size;
	double ** date;

public:

	Matrix(int size) {
		this->size = size;
		this->date = new double*[this->size];
		for (int row=0;row<size;row++) {
			this->date[row] = new double[this->size];
			for(int col=0;col<size;col++) {
				this->date[row][col] = 0;
			}
		}
	}

	Matrix (Matrix& backup) {
		this->size = backup.size;
		this->date = new double*[this->size];
		for(int row=0;row<this->size;row++) {
			this->date[row] = new double[this->size];
			for(int col=0;col<this->size;col++) {
				this->date[row][col] = backup.date[row][col];
			}
		}
	}

	friend ostream& operator<<(ostream&, const Matrix&);
	friend Matrix operator * (double number, const Matrix& first);
	friend istream& operator>>(istream& s, const Matrix& o);

	Matrix operator * (double number) {
		Matrix result(this->size);
		for(int row=0;row<result.size;row++) {
			for(int col=0;col<result.size;col++) {
				result.date[row][col] = this->date[row][col] * number;
			}
		}
		return result;
	}

	Matrix operator + (const Matrix& second) {
		Matrix result(this->size);
		if(this->size != second.size) {
			return result;
		} else {
			for(int row=0;row<result.size;row++) {
				for(int col=0;col<result.size;col++) {
					result.date[row][col] = this->date[row][col] + second.date[row][col];
				}
			}
			return result;
		}
	}

	Matrix operator = (const Matrix& second) {
		this->size = second.size;
		for(int row=0;row<this->size;row++) {
			for(int col=0;col<this->size;col++) {
				this->date[row][col] = second.date[row][col];
			}
		}
		return *this;
	}

	Matrix operator * (const Matrix& second) {
		Matrix result(*this);
		int tmp = 0;
		for(int row=0;row<result.size;row++) {
			for(int col=0;col<result.size;col++) {
				tmp = 0;
				for(int k=0;k<result.size;k++) {
					tmp = tmp + (this->date[row][k] * second.date[k][col]);
				}
				result.date[row][col] = tmp;
			}
		}
		return result;
	}

	double* operator[](int row) {
		return this->date[row];
	}

	int getSize() {
		return size;
	}

	double getDate(int row, int col) {
		return date[row][col];
	}

	void setDate(int row, int col, double value) {
		date[row][col] = value;
	}

	virtual ~Matrix() {
		delete [] date;
	}

};

ostream& operator<<(ostream& s, const Matrix& o) {
	for(int row=0;row<o.size;row++) {
		for(int col=0;col<o.size;col++) {
			s<<o.date[row][col]<<"\t";
		}
		cout<<"\n\n";
	}
	return s;
}


istream& operator>>(istream& s, const Matrix& o) {
	cout<<"Enter matrix values:\n";
	for(int row=0;row<o.size;row++) {
		for(int col=0;col<o.size;col++) {
			cout<<row+1<<" row, "<<col+1<<" column: ";
			s>>o.date[row][col];
		}
	}
	return s;
}

Matrix operator * (double number, const Matrix& first) {
	Matrix result(first.size);
	for(int row=0;row<result.size;row++) {
		for(int col=0;col<result.size;col++) {
			result.date[row][col] = first.date[row][col] * number;
		}
	}
	return result;
}
