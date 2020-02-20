using namespace std;

class Matrix {

	int size;
	double ** date;

public:

	Matrix(int size) {
		this->size = size;
		this->date = new double*[this->size];
		for (int i=0;i<size;i++) {
			this->date[i] = new double[this->size];
			for(int j=0;j<size;j++) {
				this->date[i][j] = 0;
			}
		}
	}

	Matrix (Matrix& backup) {
		this->size = backup.size;
		this->date = new double*[this->size];
		for(int i=0;i<this->size;i++) {
			this->date[i] = new double[this->size];
			for(int j=0;j<this->size;j++) {
				this->date[i][j] = backup.date[i][j];
			}
		}
	}

	friend ostream& operator<<(ostream&, const Matrix&);
	friend Matrix operator * (double number, const Matrix& first);
	friend istream& operator>>(istream& s, const Matrix& o);

	Matrix operator * (double number) {
		Matrix result(this->size);
		for(int i=0;i<result.size;i++) {
			for(int j=0;j<result.size;j++) {
				result.date[i][j] = this->date[i][j] * number;
			}
		}
		return result;
	}

	Matrix operator + (const Matrix& second) {
		Matrix result(this->size);
		if(this->size != second.size) {
			return result;
		} else {
			for(int i=0;i<result.size;i++) {
				for(int j=0;j<result.size;j++) {
					result.date[i][j] = this->date[i][j] + second.date[i][j];
				}
			}
			return result;
		}
	}

	Matrix operator = (const Matrix& second) {
		this->size = second.size;
		for(int i=0;i<this->size;i++) {
			for(int j=0;j<this->size;j++) {
				this->date[i][j] = second.date[i][j];
			}
		}
		return *this;
	}

	Matrix operator * (const Matrix& second) {
		Matrix result(*this);
		int tmp = 0;
		for(int i=0;i<result.size;i++) {
			for(int j=0;j<result.size;j++) {
				tmp = 0;
				for(int k=0;k<result.size;k++) {
					tmp = tmp + (this->date[i][k] * second.date[k][j]);
				}
				result.date[i][j] = tmp;
			}
		}
		return result;
	}

	double* operator[](int i) {
		return this->date[i];
	}

	int getSize() {
		return size;
	}

	double getDate(int a, int b) {
		return date[a][b];
	}

	void setDate(int row, int col, double value) {
		date[row][col] = value;
	}

	virtual ~Matrix() {
		delete [] date;
	}

};

ostream& operator<<(ostream& s, const Matrix& o) {
	for(int i=0;i<o.size;i++) {
		for(int j=0;j<o.size;j++) {
			s<<o.date[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
	return s;
}


istream& operator>>(istream& s, const Matrix& o) {
	cout<<"Enter matrix values:\n";
	for(int i=0;i<o.size;i++) {
		for(int j=0;j<o.size;j++) {
			cout<<i+1<<" row, "<<j+1<<" column: ";
			s>>o.date[i][j];
		}
	}
	return s;
}

Matrix operator * (double number, const Matrix& first) {
	Matrix result(first.size);
	for(int i=0;i<result.size;i++) {
		for(int j=0;j<result.size;j++) {
			result.date[i][j] = first.date[i][j] * number;
		}
	}
	return result;
}
