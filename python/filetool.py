import re
import os
import zipfile
class CFileTool():
    def __init__(self):
        pass
# file msg
    def groupFilePath(self,*strFileName):
        strpath=os.path.join(*strFileName)
        return strPath

    def getCurPath(self):
        return os.getcwd()

    def chCurPath(self,strNewPath):
        os.chdir(strNewPath)

    def createDir(self,strDir):
        os.mkdirs(strDir)

    def getStrAbPath(self,strRhPath):
        return os.path.abspath(strRhPath)

    def isAbPath(self,strPath):
        return os.path.isabs(strPath)

    def bet2StrRhPath(strTarget,strSource):
        os.path.relpath(strTarget,strSource)

    def getFileNameFromPath(self,strPath):
        return os.path.dirname(strPath)

    def getFilePathFromPath(self,strPath):
        return os.path.basename(strPath)
    
    def getPathlist(self,strPath):
        return strpath.split(os.path.sep)

    def getFileByteSize(self,strFilePath):
        return os.path.getsize(strFilePath)

    def getAllFileInDirList(self,strDir):
        return os.listdir(strDir)

    def isFileExit(self,strPath):
        return os.path.exists(strPath)

    def isFile(self,strPath):
        return os.path.isfile(strPath)

    def isDir(self,strDir):
        return os.path.isdir(strDir)
# file read & write
    def setFile(self,strpath,mode):
        try:
            self.mfile=open(strPath,mode)
        except IOError:
            print("file not accessible")
        except FileNotFoundError:
            print("file not found")

    def fileReadMode(self,strpath,mode):
        strmode=str(mode)
        if (os.access(strpath,mode)):
            print("success"+strmode)
            return true
        else:
            print("fail"+strmode)
            return fasle

    def fileToStr(self,strFilePath):
        return self.mfile.read()

    def fileToLines(self,strFilePath):
        return self.mfile.readlines()
    
    def writeFile(self,data):
        self.mfile.write(data)

    def closeFile(self):
        self.mfile.close()
# zip file
    def zipFileInit(self,strPath):
        self.mzipfile=zipfile.ZipFile(strpath)

    def zipFileClose(self):
        self.mzipfile.close()

    def zipFilesize(self,strFile):
         return self.mzipfile.getinfo(strFile).file_size

    def unZIpFile(self,strUnzipPath):
         self.mzipfile.extractall(strUnZipPath)
    
    def zipFile(self,strfilepath,mode,strZipFile):
        newZipfile=zipfile.ZipFile(strZipFile,mode)
        newZipfile.write(strfilepath,compress_type=zipfile.ZIP_DEFLATED)
        newZipfile.close()
if __name__=="__main__":
    mfile=CFileTool()
    print(mfile.getCurPath())


           
