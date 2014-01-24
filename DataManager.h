#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "Utils.h"
class Metadata;

class DataManager {

public:
    DataManager(const Metadata &meta);
   ~DataManager();

    float* GetDataPtr(int t) { return dataSequence[t].data(); }
    float* GetTFMap()        { return tfMap.data(); }
    int GetTFRes()           { return tfRes > 0 ? tfRes : DEFAULT_TF_RES; }
    vec3i GetBlockDim()      { return blockDim; }

    void LoadDataSequence(const Metadata& meta, const vec3i& gridDim, const vec3i& blockIdx, const int currentT);
    void SaveMaskVolume(float *pData, const Metadata& meta, const int timestep);

private:
    void preprocessData(std::vector<float>& data);

    std::unordered_map<int, std::vector<float> > dataSequence;
    std::vector<float> tfMap;
    vec3i blockDim;

    int volumeSize;
    int tfRes;
};

#endif // DATAMANAGER_H
