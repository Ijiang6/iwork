import pandas as pd

#pandas api
#pandas.read_excel(io, sheet_name=0, header=0, names=None, index_col=None,
# usecols=None, squeeze=False, dtype=None, engine=None, converters=None,
# true_values=None, false_values=None, skiprows=None, nrows=None, na_values=None,
# keep_default_na=True, verbose=False, parse_dates=False, date_parser=None,
# thousands=None, comment=None, skip_footer=0, skipfooter=0, convert_float=True,
# mangle_dupe_cols=True, **kwds)
#read excel
excel_path = '/home/hacker/PycharmProjects/excelpy/增值税出口退税政策汇编完整版.xlsx'
def read_excel_default(path):
    excel_file = pd.read_excel(path);
    data=excel_file.head();#默认返回5行数据
    return data;
def read_excel_index(path, index):
    if(index <0):
        index =1
    excel_file =pd.read_excel(path,sheet_name=index)
    data = excel_file.values
    return data
def read_excel_row_indexs(path):
    excel_file = pd.read_excel(path)
    data = excel_file.index.values
    return data
def read_excel_column_name(path):
    excel_file = pd.read_excel(path)
    data = excel_file.columns.values
    return data
def read_excel_row_column(path,row,column):
    excel_file = pd.read_excel(path)
    data = excel_file.ix[row,column].values
    return data

if __name__ =='__main__':
    data=read_excel_column_name(excel_path)
    print('read_excel_column_name:\n{0}'.format(data))

    data=read_excel_row_indexs(excel_path)
    print('read_excel_indexs:\n{0}'.format(data))

    row=[1,2]
    column=['政策整理汇编']
    data=read_excel_row_column(excel_path,row,column)
    print('read_excel_row_column:\n{0}'.format(data))
