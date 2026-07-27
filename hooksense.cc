
-- BYPASS 1: Core Anti-Kick (Essential)
-- Modifies a core script to nullify kick actions. This is fundamental.
for k, v in pairs(getgc(true)) do
    if pcall(function()
        return rawget(v, "indexInstance")
    end) and type(rawget(v, "indexInstance")) == "table" and (rawget(v, "indexInstance"))[1] == "kick" then
        setreadonly(v, false)
        v.tvk = {
            "kick",
            function()
                return game.Workspace:WaitForChild("")
            end
        }
    end
end

-- BYPASS 2: Adonis Cries Anti-Kick (Optional)
-- Loads an external script for additional anti-kick protection.
loadstring(game:HttpGet("https://raw.githubusercontent.com/Pixeluted/adoniscries/main/Source.lua", true))()

-- BYPASS 3: MEGGD Anti-Kick (Optional)
-- Loads another external script for further anti-kick enhancement.
loadstring(game:HttpGet('https://raw.githubusercontent.com/SUUUUUS00000/MEGGD-Anti-kick/refs/heads/main/MEGGD%20Best%20Anti-kick.lua'))()

local repo = "https://raw.githubusercontent.com/cloudsense-pub/UELinoriaLib/main/"
local Library = loadstring(game:HttpGet(repo .. "Library.lua"))()
local ThemeManager = loadstring(game:HttpGet(repo .. "addons/ThemeManager.lua"))()
local SaveManager = loadstring(game:HttpGet(repo .. "addons/SaveManager.lua"))()

Library.ShowToggleFrameInKeybinds = true
Library.ShowCustomCursor = true
Library.NotifySide = "Right" 

local Window = Library:CreateWindow({
    Title = "hooksenseㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤㅤ",
    Center = true, 
    AutoShow = true,
    Resizable = true,
    ShowCustomCursor = true,
    UnlockMouseWhileOpen = true,
    NotifySide = "Right", 
    TabPadding = 8,
    MenuFadeTime = 0.2
})

task.spawn(function()
    local MainFrame = Library.Main
    if MainFrame then
        local TabContainer = MainFrame:FindFirstChild("TabContainer") or MainFrame:FindFirstChildOfClass("Frame")
        if TabContainer then
            local ScrollFrame = Instance.new("ScrollingFrame")
            ScrollFrame.Name = "ScrollingTabContainer"
            ScrollFrame.Size = UDim2.new(1, -20, 0, 32)
            ScrollFrame.Position = UDim2.new(0, 10, 0, 38)
            ScrollFrame.BackgroundTransparency = 1
            ScrollFrame.BorderSizePixel = 0
            ScrollFrame.ScrollBarThickness = 2
            ScrollFrame.ScrollingDirection = Enum.ScrollingDirection.X
            ScrollFrame.CanvasSize = UDim2.new(0, 0, 0, 0)
            ScrollFrame.ClipsDescendants = true
            ScrollFrame.Parent = MainFrame

            local Layout = Instance.new("UIListLayout")
            Layout.FillDirection = Enum.FillDirection.Horizontal
            Layout.SortOrder = Enum.SortOrder.LayoutOrder
            Layout.Padding = UDim.new(0, 6)
            Layout.Parent = ScrollFrame

            for _, child in ipairs(TabContainer:GetChildren()) do
                if child:IsA("TextButton") or child:IsA("GuiButton") then
                    child.Parent = ScrollFrame
                end
            end
            TabContainer:Destroy()

            Layout:GetPropertyChangedSignal("AbsoluteContentSize"):Connect(function()
                ScrollFrame.CanvasSize = UDim2.new(0, Layout.AbsoluteContentSize.X + 15, 0, 0)
            end)
        end
    end
end)

getgenv().SilentAimEnabled = false
getgenv().ResolverEnabled = false
getgenv().BulletTPEnabled = false
getgenv().WallCheckEnabled = false
getgenv().TeamCheckEnabled = false
getgenv().DieCheckEnabled = true
getgenv().LookAtEnabled = false
getgenv().FOVSize = 100
getgenv().FOVVisible = true
getgenv().TracerEnabled = true

getgenv().MobileAimbotEnabled = false
getgenv().AimbotSmoothness = 0.1
getgenv().AutoPredictionEnabled = false
getgenv().PredictionValue = 0.1
getgenv().AimbotTargetPart = "Head"

getgenv().JumpSmooth = 1
getgenv().SmoothX = 1
getgenv().SmoothZ = 1
getgenv().PermLockEnabled = false
getgenv().PermTargetList = {}
getgenv().GlobalFontSetting = Enum.Font.Cartoon

getgenv().CustomFOVValue = 70

local RobloxFontsList = {}
for _, font in ipairs(Enum.Font:GetEnumItems()) do
    table.insert(RobloxFontsList, font.Name)
end
table.sort(RobloxFontsList)

getgenv().HitSoundMode = "None"
getgenv().HitSoundVolume = 2
local SoundIDs = {
    ["None"] = "None",
    ["Spark"] = "rbxassetid://110241936966089",
    ["Neverlose"] = "rbxassetid://18391691942",
    ["Rust"] = "rbxassetid://138750331387064",
    ["Fatality"] = "rbxassetid://111508823459652",
    ["Fatality 2"] = "rbxassetid://17802817724",
    ["Minecraft xp"] = "rbxassetid://17148249625",
    ["Minecraft"] = "rbxassetid://135478009117226",
    ["Crack"] = "rbxassetid://126409451844008",
    ["Skeet"] = "rbxassetid://80461265049096"
}

getgenv().HitNotifyEnabled = false 
getgenv().HitNotifyDuration = 2.5
getgenv().HitNotifyTransparency = 0.0
getgenv().HitNotifyFont = Enum.Font.Cartoon
getgenv().HitNotifyTemplate = "Hit {name} in the {part} for {dmg} dmg with {weapon}" 
getgenv().HitNotifyPosX = 50 
getgenv().HitNotifyPosY = 65 

getgenv().HitOverlayEnabled = false
getgenv().HitOverlayColor = Color3.fromRGB(255, 0, 0)

getgenv().SkyboxEnabled = false
getgenv().SelectedSkybox = "Minecraft"
local SkyboxIDs = {
    ["Minecraft"] = "rbxassetid://96736589365838",
    ["Minecraft 2"] = "rbxassetid://117301665698887",
    ["Skyblox 1"] = "rbxassetid://4951222008",
    ["Skyblox 2"] = "rbxassetid://4604073339",
    ["Skyblox 3"] = "rbxassetid://8464073887",
    ["Skyblox 4"] = "rbxassetid://12300321824",
    ["Skyblox 5"] = "rbxassetid://90988519"
}

getgenv().FOVCircleColor = Color3.fromRGB(255, 255, 255)
getgenv().FOVCircleOutlineColor = Color3.fromRGB(0, 0, 0)
getgenv().TracerLineColor = Color3.fromRGB(255, 0, 0)
getgenv().TracerLineOutlineColor = Color3.fromRGB(0, 0, 0)
getgenv().TracerThickness = 1.0
getgenv().TracerOutlineThickness = 3.0

getgenv().FOVFillEnabled = false
getgenv().FOVFillTransparency = 0.2
getgenv().FOVFillColor1 = Color3.fromRGB(255, 0, 0)
getgenv().FOVFillColor2 = Color3.fromRGB(0, 255, 0)
getgenv().FOVFillColor3 = Color3.fromRGB(0, 0, 255)
getgenv().FOVFillRotateEnabled = false
getgenv().FOVFillRotateSpeed = 1
local currentRotationAngle = 0

getgenv().TargetPartMode = "Head"
getgenv().TransitionSpeed = 5
getgenv().MaxTargetDistance = 10000

getgenv().ESPEnabled = false
getgenv().ESPName = false
getgenv().ESPHighlights = false
getgenv().ESPHealth = false
getgenv().ColorBox = Color3.fromRGB(0, 255, 255)
getgenv().ColorName = Color3.fromRGB(255, 255, 255)

getgenv().AntiAimEnabled = false
getgenv().AntiAimMode = "Spin"
getgenv().AntiAimSpeed = 15
getgenv().JitterMode = "Multi"

getgenv().ThirdPersonEnabled = false
getgenv().ThirdPersonDistance = 12
getgenv().MotionBlurEnabled = false
getgenv().MotionBlurIntensity = 1.5

getgenv().BhopEnabled = false
getgenv().BhopSpeedMultiplier = 1.5

getgenv().TargetHudToggle = true
getgenv().TargetHudPosX = 0
getgenv().TargetHudPosY = 0
getgenv().TargetHudBorderColor1 = Color3.fromRGB(0, 255, 100)
getgenv().TargetHudBorderColor2 = Color3.fromRGB(0, 150, 0)
getgenv().TargetHudHealthHigh = Color3.fromRGB(0, 255, 100)
getgenv().TargetHudHealthMid = Color3.fromRGB(255, 200, 0)
getgenv().TargetHudHealthLow = Color3.fromRGB(255, 50, 50)

getgenv().AtmosphereEnabled = false 
getgenv().AtmosphereColor = Color3.fromRGB(178, 200, 255)
getgenv().AtmosphereDecay = Color3.fromRGB(255, 178, 120)
getgenv().AtmosphereGlare = 0.4
getgenv().AtmosphereHaze = 1.2
getgenv().AtmosphereOffset = 0.25
getgenv().AtmosphereDensity = 0.35

local Camera = workspace.CurrentCamera
local Players = game.Players
local LocalPlayer = Players.LocalPlayer
local CoreGui = game:GetService("CoreGui")
local UserInputService = game:GetService("UserInputService")
local SoundService = game:GetService("SoundService")
local Lighting = game:GetService("Lighting")
local TweenService = game:GetService("TweenService")
local DisplayNameLabel, UsernameLabel, UserIdLabel, AvatarImage
local ESP_Storage = {}
local TargetVelocityHistory = {}

local TargetGuiParent = LocalPlayer:WaitForChild("PlayerGui", 5) or (CoreGui:FindFirstChild("RobloxGui") or CoreGui)

local HitOverlayGui = Instance.new("ScreenGui")
HitOverlayGui.Name = "hooksense_HitOverlayGui"
HitOverlayGui.ResetOnSpawn = false
HitOverlayGui.IgnoreGuiInset = true
HitOverlayGui.DisplayOrder = 99999
HitOverlayGui.Parent = TargetGuiParent

local OverlayFrame = Instance.new("Frame")
OverlayFrame.Name = "HitOverlay"
OverlayFrame.Size = UDim2.new(1, 0, 1, 0)
OverlayFrame.BorderSizePixel = 0
OverlayFrame.BackgroundColor3 = getgenv().HitOverlayColor
OverlayFrame.BackgroundTransparency = 1
OverlayFrame.ZIndex = 99999
OverlayFrame.Parent = HitOverlayGui

local function TriggerHitOverlay()
    if not getgenv().HitOverlayEnabled then return end
    OverlayFrame.BackgroundColor3 = getgenv().HitOverlayColor
    
    local fadeIn = TweenService:Create(OverlayFrame, TweenInfo.new(0.05, Enum.EasingStyle.Quad, Enum.EasingDirection.Out), {BackgroundTransparency = 0.5})
    local fadeOut = TweenService:Create(OverlayFrame, TweenInfo.new(0.3, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {BackgroundTransparency = 1})
    
    fadeIn:Play()
    fadeIn.Completed:Connect(function()
        task.wait(0.01)
        fadeOut:Play()
    end)
end

local CenterNotifyGui = Instance.new("ScreenGui")
CenterNotifyGui.Name = "hooksense_CenterNotifyGui"
CenterNotifyGui.ResetOnSpawn = false
CenterNotifyGui.Parent = TargetGuiParent

local CenterNotifyContainer = Instance.new("Frame")
CenterNotifyContainer.Name = "NotifyContainer"
CenterNotifyContainer.Size = UDim2.new(0.6, 0, 0.4, 0)
CenterNotifyContainer.AnchorPoint = Vector2.new(0.5, 0.5)
CenterNotifyContainer.Position = UDim2.new(getgenv().HitNotifyPosX / 100, 0, getgenv().HitNotifyPosY / 100, 0)
CenterNotifyContainer.BackgroundTransparency = 1
CenterNotifyContainer.BorderSizePixel = 0
CenterNotifyContainer.Parent = CenterNotifyGui

local CenterNotifyLayout = Instance.new("UIListLayout")
CenterNotifyLayout.FillDirection = Enum.FillDirection.Vertical
CenterNotifyLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
CenterNotifyLayout.VerticalAlignment = Enum.VerticalAlignment.Bottom
CenterNotifyLayout.SortOrder = Enum.SortOrder.LayoutOrder
CenterNotifyLayout.Padding = UDim.new(0, 5)
CenterNotifyLayout.Parent = CenterNotifyContainer

local function ShowCustomHitNotification(targetName, partName, damage, weaponName)
    if not getgenv().HitNotifyEnabled then return end
    
    weaponName = weaponName or "Hands"
    
    local notifyText = getgenv().HitNotifyTemplate
    notifyText = string.gsub(notifyText, "{name}", targetName)
    notifyText = string.gsub(notifyText, "{part}", partName)
    notifyText = string.gsub(notifyText, "{dmg}", tostring(damage))
    notifyText = string.gsub(notifyText, "{weapon}", weaponName)
    
    local NotifyLabel = Instance.new("TextLabel")
    NotifyLabel.Size = UDim2.new(1, 0, 0, 24)
    NotifyLabel.BackgroundTransparency = 1
    NotifyLabel.Text = notifyText
    NotifyLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
    NotifyLabel.TextSize = 16
    NotifyLabel.Font = getgenv().HitNotifyFont
    NotifyLabel.TextStrokeColor3 = Color3.fromRGB(0, 0, 0)
    
    NotifyLabel.Position = UDim2.new(0, 0, 0, 15)
    NotifyLabel.TextTransparency = 1
    NotifyLabel.TextStrokeTransparency = 1
    NotifyLabel.Parent = CenterNotifyContainer

    local openTween = TweenService:Create(NotifyLabel, TweenInfo.new(0.35, Enum.EasingStyle.Back, Enum.EasingDirection.Out), {
        Position = UDim2.new(0, 0, 0, 0),
        TextTransparency = getgenv().HitNotifyTransparency,
        TextStrokeTransparency = math.clamp(getgenv().HitNotifyTransparency + 0.4, 0, 1)
    })
    openTween:Play()

    task.delay(getgenv().HitNotifyDuration, function()
        if not NotifyLabel or not NotifyLabel.Parent then return end
        
        local closeTween = TweenService:Create(NotifyLabel, TweenInfo.new(0.4, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {
            Position = UDim2.new(0, 0, 0, 25),
            TextTransparency = 1,
            TextStrokeTransparency = 1
        })
        closeTween:Play()
        closeTween.Completed:Connect(function()
            NotifyLabel:Destroy()
        end)
    end)
end

local function PlayHitSound()
    if getgenv().HitSoundMode == "None" or not SoundIDs[getgenv().HitSoundMode] then return end
    local Sound = Instance.new("Sound")
    Sound.SoundId = SoundIDs[getgenv().HitSoundMode]
    Sound.Volume = getgenv().HitSoundVolume
    Sound.PlayOnRemove = true
    Sound.Parent = SoundService
    Sound:Destroy()
end

local function UpdateSkybox()
    for _, obj in ipairs(Lighting:GetChildren()) do
        if obj:IsA("Sky") and (obj.Name == "hooksenseSky" or obj.Name == "Sky") then
            obj:Destroy()
        end
    end
    if getgenv().SkyboxEnabled and SkyboxIDs[getgenv().SelectedSkybox] then
        local assetId = SkyboxIDs[getgenv().SelectedSkybox]
        local success, result = pcall(function() return game:GetObjects(assetId)[1] end)
        if success and result and result:IsA("Sky") then
            local NewSky = result:Clone()
            NewSky.Name = "hooksenseSky"
            NewSky.Parent = Lighting
        else
            local NewSky = Instance.new("Sky")
            NewSky.Name = "hooksenseSky"
            NewSky.SkyboxBk = assetId
            NewSky.SkyboxDn = assetId
            NewSky.SkyboxFt = assetId
            NewSky.SkyboxLf = assetId
            NewSky.SkyboxRt = assetId
            NewSky.SkyboxUp = assetId
            NewSky.Parent = Lighting
        end
    end
end

local function UpdateAtmosphere()
    local atmos = Lighting:FindFirstChildOfClass("Atmosphere")
    if getgenv().AtmosphereEnabled then
        if not atmos then
            atmos = Instance.new("Atmosphere")
            atmos.Parent = Lighting
        end
        atmos.Color = getgenv().AtmosphereColor
        atmos.Decay = getgenv().AtmosphereDecay
        atmos.Glare = getgenv().AtmosphereGlare
        atmos.Haze = getgenv().AtmosphereHaze
        atmos.Offset = getgenv().AtmosphereOffset
        atmos.Density = getgenv().AtmosphereDensity
        
        if not Lighting:FindFirstChildOfClass("Sky") then
            local DefaultSky = Instance.new("Sky")
            DefaultSky.Name = "hooksenseDefaultSky"
            DefaultSky.Parent = Lighting
        end
    else
        if atmos then
            atmos:Destroy()
        end
        if not getgenv().SkyboxEnabled then
            local defaultSky = Lighting:FindFirstChild("hooksenseDefaultSky")
            if defaultSky then
                defaultSky:Destroy()
            end
        end
    end
end

UpdateAtmosphere()

local TargetGui = Instance.new("ScreenGui")
TargetGui.Name = "hooksenseTargetHudGui"
TargetGui.ResetOnSpawn = false
TargetGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
TargetGui.Parent = TargetGuiParent

local MainCanvas = Instance.new("CanvasGroup")
MainCanvas.Name = "MainTargetHUD"
MainCanvas.Size = UDim2.new(0, 280, 0, 90)
MainCanvas.AnchorPoint = Vector2.new(1, 0)
MainCanvas.Position = UDim2.new(1, -20, 0, 20)
MainCanvas.BackgroundColor3 = Color3.fromRGB(0, 0, 0)
MainCanvas.BackgroundTransparency = 0.15 
MainCanvas.GroupTransparency = 1 
MainCanvas.Visible = false
MainCanvas.Parent = TargetGui

local Corner = Instance.new("UICorner")
Corner.CornerRadius = UDim.new(0, 10)
Corner.Parent = MainCanvas

local Stroke = Instance.new("UIStroke")
Stroke.Color = Color3.fromRGB(255, 255, 255)
Stroke.Thickness = 1.8
Stroke.ApplyStrokeMode = Enum.ApplyStrokeMode.Border
Stroke.Parent = MainCanvas

local BorderGradient = Instance.new("UIGradient")
BorderGradient.Color = ColorSequence.new({
    ColorSequenceKeypoint.new(0, getgenv().TargetHudBorderColor1),
    ColorSequenceKeypoint.new(1, getgenv().TargetHudBorderColor2)
})
BorderGradient.Rotation = 45
BorderGradient.Parent = Stroke

local AvatarFrame = Instance.new("Frame")
AvatarFrame.Size = UDim2.new(0, 56, 0, 56)
AvatarFrame.Position = UDim2.new(0, 14, 0, 14)
AvatarFrame.BackgroundColor3 = Color3.fromRGB(15, 15, 22)
AvatarFrame.BorderSizePixel = 0
AvatarFrame.Parent = MainCanvas

local AvatarCorner = Instance.new("UICorner")
AvatarCorner.CornerRadius = UDim.new(1, 0) 
AvatarCorner.Parent = AvatarFrame

local AvatarStroke = Instance.new("UIStroke")
AvatarStroke.Color = Color3.fromRGB(0, 0, 0)
AvatarStroke.Thickness = 1.5
AvatarStroke.Parent = AvatarFrame

AvatarImage = Instance.new("ImageLabel")
AvatarImage.Size = UDim2.new(1, -4, 1, -4)
AvatarImage.Position = UDim2.new(0, 2, 0, 2)
AvatarImage.BackgroundTransparency = 1
AvatarImage.Parent = AvatarFrame

local ImgCorner = Instance.new("UICorner")
ImgCorner.CornerRadius = UDim.new(1, 0)
ImgCorner.Parent = AvatarImage

local InfoFrame = Instance.new("Frame")
InfoFrame.Size = UDim2.new(1, -95, 1, -40)
InfoFrame.Position = UDim2.new(0, 84, 0, 12)
InfoFrame.BackgroundTransparency = 1
InfoFrame.Parent = MainCanvas

DisplayNameLabel = Instance.new("TextLabel")
DisplayNameLabel.Size = UDim2.new(1, 0, 0, 18)
DisplayNameLabel.Font = getgenv().GlobalFontSetting
DisplayNameLabel.TextSize = 14
DisplayNameLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
DisplayNameLabel.TextXAlignment = Enum.TextXAlignment.Left
DisplayNameLabel.Text = "No Target"
DisplayNameLabel.BackgroundTransparency = 1
DisplayNameLabel.Parent = InfoFrame

UsernameLabel = Instance.new("TextLabel")
UsernameLabel.Size = UDim2.new(1, 0, 0, 14)
UsernameLabel.Position = UDim2.new(0, 0, 0, 18)
UsernameLabel.Font = getgenv().GlobalFontSetting
UsernameLabel.TextSize = 11
UsernameLabel.TextColor3 = Color3.fromRGB(140, 140, 155)
UsernameLabel.TextXAlignment = Enum.TextXAlignment.Left
UsernameLabel.Text = "@none"
UsernameLabel.BackgroundTransparency = 1
UsernameLabel.Parent = InfoFrame

UserIdLabel = Instance.new("TextLabel")
UserIdLabel.Size = UDim2.new(1, 0, 0, 12)
UserIdLabel.Position = UDim2.new(0, 0, 0, 32)
UserIdLabel.Font = getgenv().GlobalFontSetting
UserIdLabel.TextSize = 10
UserIdLabel.TextColor3 = Color3.fromRGB(255, 255, 255)
UserIdLabel.TextXAlignment = Enum.TextXAlignment.Left
UserIdLabel.Text = "USER ID: --"
UserIdLabel.BackgroundTransparency = 1
UserIdLabel.Parent = InfoFrame

local HealthBackground = Instance.new("Frame")
HealthBackground.Size = UDim2.new(1, -28, 0, 5)
HealthBackground.Position = UDim2.new(0, 14, 1, -16)
HealthBackground.BackgroundColor3 = Color3.fromRGB(20, 25, 20)
HealthBackground.BorderSizePixel = 0
HealthBackground.Parent = MainCanvas

local HealthBarCorner = Instance.new("UICorner")
HealthBarCorner.CornerRadius = UDim.new(0, 4)
HealthBarCorner.Parent = HealthBackground

local HealthBar = Instance.new("Frame")
HealthBar.Size = UDim2.new(1, 0, 1, 0)
HealthBar.BackgroundColor3 = getgenv().TargetHudHealthHigh
HealthBar.BorderSizePixel = 0
HealthBar.Parent = HealthBackground

local MainBarCorner = Instance.new("UICorner")
MainBarCorner.CornerRadius = UDim.new(0, 4)
MainBarCorner.Parent = HealthBar

local isHudVisible = false
local function ToggleHUD(state)
    if state and getgenv().TargetHudToggle then
        if not isHudVisible then
            isHudVisible = true
            MainCanvas.Visible = true
            TweenService:Create(MainCanvas, TweenInfo.new(0.2, Enum.EasingStyle.Cubic, Enum.EasingDirection.Out), {GroupTransparency = 0}):Play()
        end
    else
        if isHudVisible then
            isHudVisible = false
            local fadeOut = TweenService:Create(MainCanvas, TweenInfo.new(0.2, Enum.EasingStyle.Cubic, Enum.EasingDirection.In), {GroupTransparency = 1})
            fadeOut:Play()
            fadeOut.Completed:Connect(function()
                if not isHudVisible then MainCanvas.Visible = false end
            end)
        end
    end
end

local EspGui = Instance.new("ScreenGui")
EspGui.Name = "hooksenseModernEspGui"
EspGui.ResetOnSpawn = false
EspGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
EspGui.Parent = TargetGuiParent

local DeltaGradientGui = Instance.new("ScreenGui")
DeltaGradientGui.Name = "hooksense_DeltaGradientGui"
DeltaGradientGui.ResetOnSpawn = false
DeltaGradientGui.IgnoreGuiInset = true
DeltaGradientGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
DeltaGradientGui.Parent = TargetGuiParent

local FOVFillFrame = Instance.new("Frame")
FOVFillFrame.Name = "FOVGradientFrame"
FOVFillFrame.AnchorPoint = Vector2.new(0.5, 0.5)
FOVFillFrame.BorderSizePixel = 0
FOVFillFrame.BackgroundTransparency = 1
FOVFillFrame.Visible = false
FOVFillFrame.Parent = DeltaGradientGui

local FOVFillCorner = Instance.new("UICorner")
FOVFillCorner.CornerRadius = UDim.new(1, 0)
FOVFillCorner.Parent = FOVFillFrame

local FOVFillGradient = Instance.new("UIGradient")
FOVFillGradient.Parent = FOVFillFrame

-- [External-like Premium FOV Draw]
local FOVCircleOutline = Drawing.new("Circle")
FOVCircleOutline.Thickness = 2.0 -- เงาด้านหลังหนาขึ้นเล็กน้อยเพื่อความคมชัด
FOVCircleOutline.NumSides = 144  -- 144 ด้านเนียนกริบไม่มีเหลี่ยมสไตล์ External overlay
FOVCircleOutline.Filled = false
FOVCircleOutline.Visible = getgenv().FOVVisible

local FOVCircle = Drawing.new("Circle")
FOVCircle.Thickness = 1.0  -- เส้นขอบหลักคมกริบขนาด 1 พิกเซล
FOVCircle.NumSides = 144   -- โค้งมนสูงสุดระดับโปรแกรมภายนอก
FOVCircle.Filled = false
FOVCircle.Visible = getgenv().FOVVisible

local TracerLineOutline = Drawing.new("Line")
TracerLineOutline.Thickness = 3.0
TracerLineOutline.Transparency = 1.0

local TracerLine = Drawing.new("Line")
TracerLine.Thickness = 1.0
TracerLine.Transparency = 0.8

local function getScreenCenter()
    return Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
end

local function isBehindWall(targetPart)
    if not getgenv().WallCheckEnabled then return false end
    local Parts = Camera:GetPartsObscuringTarget({targetPart.Position}, {LocalPlayer.Character, targetPart.Parent})
    return #Parts > 0
end

local function isDead(humanoid, char)
    if not getgenv().DieCheckEnabled then return false end
    if humanoid and humanoid.Health <= 0 then return true end
    if char and not char:IsDescendantOf(workspace) then return true end
    return false
end

local CurrentAimTargetPosition = nil
local CurrentTargetPlayer = nil
local CurrentTargetCharacter = nil
local lastTarget = nil
local interpolationProgress = 0

task.spawn(function()
    while task.wait(0.01) do
        -- Track True Velocity for Resolver Logic
        for _, p in ipairs(Players:GetPlayers()) do
            if p.Character and p.Character:FindFirstChild("HumanoidRootPart") then
                local hrp = p.Character.HumanoidRootPart
                local hist = TargetVelocityHistory[p.Name]
                local currentTick = tick()
                if not hist then
                    TargetVelocityHistory[p.Name] = {Pos = hrp.Position, Time = currentTick, Velocity = Vector3.new(0, 0, 0)}
                else
                    local dt = currentTick - hist.Time
                    if dt > 0.005 then
                        local calculatedVel = (hrp.Position - hist.Pos) / dt
                        hist.Velocity = calculatedVel
                        hist.Pos = hrp.Position
                        hist.Time = currentTick
                    end
                end
            end
        end

        if not getgenv().SilentAimEnabled and not getgenv().MobileAimbotEnabled then
            CurrentAimTargetPosition = nil
            CurrentTargetPlayer = nil
            CurrentTargetCharacter = nil
            lastTarget = nil
            interpolationProgress = 0
        else
            local TempTargetChar = nil
            local TempPlayer = nil
            local MaxDistance = getgenv().FOVSize
            local Center = getScreenCenter()
            local MyRoot = LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
            local PotentialTargets = {}

            if getgenv().PermLockEnabled and #getgenv().PermTargetList > 0 then
                for _, pName in ipairs(getgenv().PermTargetList) do
                    local targetPlayerObject = Players:FindFirstChild(pName)
                    if targetPlayerObject and targetPlayerObject.Character then
                        local char = targetPlayerObject.Character
                        local rootPart = char:FindFirstChild("HumanoidRootPart")
                        local humanoid = char:FindFirstChildOfClass("Humanoid")
                        if rootPart and humanoid and not isDead(humanoid, char) then
                            if MyRoot and (rootPart.Position - MyRoot.Position).Magnitude <= getgenv().MaxTargetDistance then
                                if not isBehindWall(rootPart) then
                                    if not (getgenv().TeamCheckEnabled and targetPlayerObject.Team == LocalPlayer.Team) then
                                        TempTargetChar = char
                                        TempPlayer = targetPlayerObject
                                        break
                                    end
                                end
                            end
                        end
                    end
                end
            end

            if not TempTargetChar then
                for _, player in ipairs(Players:GetPlayers()) do
                    if player ~= LocalPlayer and player.Character then
                        table.insert(PotentialTargets, player.Character)
                    end
                end
                for _, char in ipairs(PotentialTargets) do
                    local rootPart = char:FindFirstChild("HumanoidRootPart")
                    local humanoid = char:FindFirstChildOfClass("Humanoid")
                    if rootPart and humanoid then
                        if isDead(humanoid, char) then continue end
                        if MyRoot and (rootPart.Position - MyRoot.Position).Magnitude > getgenv().MaxTargetDistance then continue end
                        if isBehindWall(rootPart) then continue end
                        local targetPlayerObject = Players:GetPlayerFromCharacter(char)
                        if getgenv().TeamCheckEnabled and targetPlayerObject and targetPlayerObject.Team == LocalPlayer.Team then continue end
                        local ScreenPosition, OnScreen = Camera:WorldToViewportPoint(rootPart.Position)
                        if OnScreen then
                            local DistanceToCenter = (Vector2.new(ScreenPosition.X, ScreenPosition.Y) - Center).Magnitude
                            if DistanceToCenter < MaxDistance then
                                TempTargetChar = char
                                TempPlayer = targetPlayerObject
                                MaxDistance = DistanceToCenter
                            end
                        end
                    end
                end
            end

            CurrentTargetPlayer = TempPlayer
            CurrentTargetCharacter = TempTargetChar

            if TempTargetChar then
                local targetPartName = getgenv().MobileAimbotEnabled and getgenv().AimbotTargetPart or getgenv().TargetPartMode
                local head = TempTargetChar:FindFirstChild("Head")
                local root = TempTargetChar:FindFirstChild("HumanoidRootPart")
                
                -- [ระบบคำนวณชิ้นส่วนแบบ Closet / Closest Part จากหน้าจอ]
                local targetPartObj = nil
                if targetPartName == "Closet" then
                    local closestPart = nil
                    local minPartDist = math.huge
                    for _, part in ipairs(TempTargetChar:GetChildren()) do
                        if part:IsA("BasePart") then
                            local screenPos, onScreen = Camera:WorldToViewportPoint(part.Position)
                            if onScreen then
                                local dist = (Vector2.new(screenPos.X, screenPos.Y) - Center).Magnitude
                                if dist < minPartDist then
                                    minPartDist = dist
                                    closestPart = part
                                end
                            end
                        end
                    end
                    targetPartObj = closestPart or head or root
                else
                    targetPartObj = TempTargetChar:FindFirstChild(targetPartName) or head or root
                end

                if targetPartObj then
                    local basePosition = targetPartObj.Position
                    if getgenv().AutoPredictionEnabled and root then
                        local ping = LocalPlayer:GetNetworkPing()
                        local targetedVelocity = root.Velocity

                        if getgenv().ResolverEnabled then
                            -- Harsh Resolver / Anti-Aim / Desync / Velocity Spoof Detection
                            local isVelocitySpoofed = (targetedVelocity.Magnitude > 75) or 
                                                      (math.abs(targetedVelocity.Y) > 50) or 
                                                      (targetedVelocity.Magnitude < 0.1 and root.AssemblyLinearVelocity.Magnitude > 10) or
                                                      (targetedVelocity.X ~= targetedVelocity.X) -- NaN Check
                            
                            if isVelocitySpoofed then
                                local historyData = TargetVelocityHistory[TempPlayer and TempPlayer.Name or ""]
                                if historyData and historyData.Velocity.Magnitude < 150 then
                                    targetedVelocity = historyData.Velocity
                                else
                                    targetedVelocity = Vector3.new(0, 0, 0) -- Completely neutralize desync/anti-aim
                                end
                            end
                        end

                        basePosition = basePosition + (targetedVelocity * ping * getgenv().PredictionValue)
                    end
                    if getgenv().TargetPartMode == "Root to Head" and not getgenv().MobileAimbotEnabled then
                        if lastTarget ~= TempTargetChar then
                            lastTarget = TempTargetChar
                            interpolationProgress = 0
                        end
                        interpolationProgress = math.clamp(interpolationProgress + (0.01 * getgenv().TransitionSpeed), 0, 1)
                        CurrentAimTargetPosition = root.Position:Lerp(head.Position, interpolationProgress)
                    else
                        CurrentAimTargetPosition = basePosition
                        lastTarget = TempTargetChar
                    end
                else
                    CurrentAimTargetPosition = nil
                end
            else
                lastTarget = nil
                interpolationProgress = 0
                CurrentAimTargetPosition = nil
            end
        end
    end
end)

local CurrentConnectedHumanoid = nil
local HealthConnection = nil
local function BindHealthTracker(targetPlayer)
    if not targetPlayer or not targetPlayer.Character then return end
    local hum = targetPlayer.Character:FindFirstChildOfClass("Humanoid")
    if not hum then return end
    if CurrentConnectedHumanoid == hum then return end
    if HealthConnection then HealthConnection:Disconnect() end
    CurrentConnectedHumanoid = hum
    local lastHealth = hum.Health
    HealthConnection = hum:GetPropertyChangedSignal("Health"):Connect(function()
        if CurrentTargetPlayer == targetPlayer and hum.Health < lastHealth then
            local damageCalculated = math.floor(lastHealth - hum.Health)
            task.spawn(PlayHitSound)
            task.spawn(TriggerHitOverlay) 
            local hitPartName = getgenv().TargetPartMode
            if hitPartName == "Root to Head" then
                hitPartName = "Body/Head"
            elseif hitPartName == "HumanoidRootPart" then
                hitPartName = "Torso"
            end
            
            local weaponName = "Hands"
            if LocalPlayer.Character then
                local heldTool = LocalPlayer.Character:FindFirstChildOfClass("Tool")
                if heldTool then
                    weaponName = heldTool.Name
                end
            end
            
            task.spawn(ShowCustomHitNotification, targetPlayer.Name, hitPartName, damageCalculated, weaponName)
        end
        lastHealth = hum.Health
    end)
end

local function CreateESP(player)
    local Billboard = Instance.new("BillboardGui")
    Billboard.Name = player.Name .. "_BillboardESP"
    Billboard.Size = UDim2.new(0, 200, 0, 50)
    Billboard.AlwaysOnTop = true
    Billboard.ExtentsOffset = Vector3.new(0, 2.5, 0)
    Billboard.Enabled = false
    Billboard.Parent = EspGui

    local NameLabel = Instance.new("TextLabel")
    NameLabel.Size = UDim2.new(1, 0, 0, 16)
    NameLabel.Font = getgenv().GlobalFontSetting
    NameLabel.TextSize = 13
    NameLabel.TextColor3 = getgenv().ColorName
    NameLabel.TextStrokeColor3 = Color3.fromRGB(0, 0, 0)
    NameLabel.TextStrokeTransparency = 0
    NameLabel.BackgroundTransparency = 1
    NameLabel.Parent = Billboard

    local HealthLabel = Instance.new("TextLabel")
    HealthLabel.Size = UDim2.new(1, 0, 0, 14)
    HealthLabel.Position = UDim2.new(0, 0, 0, 16)
    HealthLabel.Font = getgenv().GlobalFontSetting
    HealthLabel.TextSize = 12
    HealthLabel.TextStrokeColor3 = Color3.fromRGB(0, 0, 0)
    HealthLabel.TextStrokeTransparency = 0
    HealthLabel.BackgroundTransparency = 1
    HealthLabel.Parent = Billboard

    ESP_Storage[player] = {
        BillboardGui = Billboard,
        NameTag = NameLabel,
        HealthTag = HealthLabel
    }
end

local function RemoveESP(player)
    if ESP_Storage[player] then
        ESP_Storage[player].BillboardGui:Destroy()
        ESP_Storage[player] = nil
    end
    if player.Character then
        local highlight = player.Character:FindFirstChild("hooksenseHighlight")
        if highlight then highlight:Destroy() end
    end
end

for _, player in ipairs(Players:GetPlayers()) do
    if player ~= LocalPlayer then CreateESP(player) end
end
Players.PlayerAdded:Connect(function(player)
    if player ~= LocalPlayer then CreateESP(player) end
end)
Players.PlayerRemoving:Connect(function(player)
    RemoveESP(player)
end)

local function ResetCamera()
    Camera.CameraType = Enum.CameraType.Custom
    local char = LocalPlayer.Character
    local hum = char and char:FindFirstChildOfClass("Humanoid")
    if hum then
        hum.CameraOffset = Vector3.new(0, 0, 0)
    end
    LocalPlayer.CameraMaxZoomDistance = 128
    LocalPlayer.CameraMinZoomDistance = 0.5
end

local RunService = game:GetService("RunService")
local spinAngle = 0
local jitterToggle = false
local LastLoggedHudTargetId = 0
local currentHudHealthLerp = 0 
local LastCameraRotation = Camera.CFrame.LookVector

RunService.RenderStepped:Connect(function()
    local Center = getScreenCenter()
    local ShowCircle = getgenv().FOVVisible and (getgenv().SilentAimEnabled or getgenv().MobileAimbotEnabled)
    
    FOVCircleOutline.Position = Center
    FOVCircleOutline.Radius = getgenv().FOVSize
    FOVCircleOutline.Visible = ShowCircle
    FOVCircleOutline.Color = getgenv().FOVCircleOutlineColor

    FOVCircle.Position = Center
    FOVCircle.Radius = getgenv().FOVSize
    FOVCircle.Visible = ShowCircle
    FOVCircle.Color = getgenv().FOVCircleColor

    if ShowCircle and getgenv().FOVFillEnabled then
        FOVFillFrame.Position = UDim2.new(0, Center.X, 0, Center.Y)
        FOVFillFrame.Size = UDim2.new(0, getgenv().FOVSize * 2, 0, getgenv().FOVSize * 2)
        
        FOVFillGradient.Color = ColorSequence.new({
            ColorSequenceKeypoint.new(0, getgenv().FOVFillColor1),
            ColorSequenceKeypoint.new(0.5, getgenv().FOVFillColor2),
            ColorSequenceKeypoint.new(1, getgenv().FOVFillColor3)
        })
        
        FOVFillFrame.BackgroundTransparency = getgenv().FOVFillTransparency
        
        if getgenv().FOVFillRotateEnabled then
            currentRotationAngle = (currentRotationAngle + (0.5 * getgenv().FOVFillRotateSpeed)) % 360
        end
        FOVFillGradient.Rotation = currentRotationAngle
        FOVFillFrame.Visible = true
    else
        FOVFillFrame.Visible = false
    end

    if (getgenv().SilentAimEnabled or getgenv().MobileAimbotEnabled) and getgenv().TracerEnabled and CurrentAimTargetPosition then
        local TargetPos, OnScreen = Camera:WorldToViewportPoint(CurrentAimTargetPosition)
        if OnScreen then
            local ToPos = Vector2.new(TargetPos.X, TargetPos.Y)
            TracerLineOutline.From = Center
            TracerLineOutline.To = ToPos
            TracerLineOutline.Visible = true
            TracerLineOutline.Color = getgenv().TracerLineOutlineColor
            TracerLineOutline.Thickness = getgenv().TracerOutlineThickness

            TracerLine.From = Center
            TracerLine.To = ToPos
            TracerLine.Visible = true
            TracerLine.Color = getgenv().TracerLineColor
            TracerLine.Thickness = getgenv().TracerThickness
        else
            TracerLineOutline.Visible = false
            TracerLine.Visible = false
        end
    else
        TracerLineOutline.Visible = false
        TracerLine.Visible = false
    end

    if getgenv().MobileAimbotEnabled and CurrentAimTargetPosition then
        local targetCFrame = CFrame.new(Camera.CFrame.Position, CurrentAimTargetPosition)
        Camera.CFrame = Camera.CFrame:Lerp(targetCFrame, getgenv().AimbotSmoothness)
    end

    MainCanvas.Position = UDim2.new(1, -20 + getgenv().TargetHudPosX, 0, 20 + getgenv().TargetHudPosY)

    if (getgenv().SilentAimEnabled or getgenv().MobileAimbotEnabled) and CurrentTargetPlayer and CurrentTargetPlayer.Character and getgenv().TargetHudToggle then
        local Hum = CurrentTargetPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Hum then
            DisplayNameLabel.Text = CurrentTargetPlayer.DisplayName
            UsernameLabel.Text = "@" .. CurrentTargetPlayer.Name
            UserIdLabel.Text = "USER ID: " .. tostring(CurrentTargetPlayer.UserId)
            
            local pct = math.clamp(Hum.Health / Hum.MaxHealth, 0, 1)
            
            if CurrentTargetPlayer.UserId ~= LastLoggedHudTargetId then
                currentHudHealthLerp = pct
                LastLoggedHudTargetId = CurrentTargetPlayer.UserId
                AvatarImage.Image = "rbxthumb://type=AvatarHeadShot&id=" .. tostring(CurrentTargetPlayer.UserId) .. "&w=150&h=150"
            end
            
            currentHudHealthLerp = currentHudHealthLerp + (pct - currentHudHealthLerp) * 0.12
            HealthBar.Size = UDim2.new(currentHudHealthLerp, 0, 1, 0)
            
            if currentHudHealthLerp > 0.6 then
                HealthBar.BackgroundColor3 = getgenv().TargetHudHealthHigh
            elseif currentHudHealthLerp > 0.3 then
                HealthBar.BackgroundColor3 = getgenv().TargetHudHealthMid
            else
                HealthBar.BackgroundColor3 = getgenv().TargetHudHealthLow
            end
            
            BindHealthTracker(CurrentTargetPlayer)
            ToggleHUD(true)
        else
            ToggleHUD(false)
            LastLoggedHudTargetId = 0
        end
    else
        ToggleHUD(false)
        LastLoggedHudTargetId = 0
    end

    if getgenv().SilentAimEnabled and getgenv().LookAtEnabled and LocalPlayer.Character then
        local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
        local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Root and Humanoid and Humanoid.Health > 0 and not getgenv().AntiAimEnabled then
            if CurrentAimTargetPosition then
                Humanoid.AutoRotate = false
                local lookVector = Vector3.new(CurrentAimTargetPosition.X, Root.Position.Y, CurrentAimTargetPosition.Z)
                Root.CFrame = CFrame.lookAt(Root.Position, lookVector)
            else
                Humanoid.AutoRotate = true
            end
        end
    end

    if getgenv().AntiAimEnabled and LocalPlayer.Character then
        local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
        local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
        if Root and Humanoid and Humanoid.Health > 0 then
            Humanoid.AutoRotate = false
            if getgenv().AntiAimMode == "Spin" then
                spinAngle = (spinAngle + getgenv().AntiAimSpeed) % 360
                Root.CFrame = CFrame.new(Root.Position) * CFrame.Angles(0, math.rad(spinAngle), 0)
            elseif getgenv().AntiAimMode == "Jitter" then
                local intensity = 1
                if getgenv().JitterMode == "Multi" then intensity = math.random(1, 5)
                elseif getgenv().JitterMode == "5x always" then intensity = 5
                elseif getgenv().JitterMode == "3x always" then intensity = 3
                elseif getgenv().JitterMode == "2x always" then intensity = 2
                elseif getgenv().JitterMode == "random" then intensity = math.random(1, 5)
                else intensity = math.random(1, 5) end
                jitterToggle = not jitterToggle
                local _, cameraY, _ = Camera.CFrame:ToOrientation()
                local jitterOffset = jitterToggle and math.rad(22.5 * intensity) or math.rad(-22.5 * intensity)
                Root.CFrame = CFrame.new(Root.Position) * CFrame.Angles(0, cameraY + jitterOffset, 0)
                local LowerTorso = LocalPlayer.Character:FindFirstChild("LowerTorso") or LocalPlayer.Character:FindFirstChild("Torso")
                if LowerTorso and LowerTorso:FindFirstChild("RootJoint") then
                    LowerTorso.RootJoint.Transform = CFrame.Angles(0, jitterOffset, 0)
                end
            end
        end
    else
        if LocalPlayer.Character then
            local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
            if Humanoid then
                if not getgenv().LookAtEnabled or (getgenv().LookAtEnabled and not CurrentAimTargetPosition) then
                    Humanoid.AutoRotate = true
                end
            end
            local LowerTorso = LocalPlayer.Character:FindFirstChild("LowerTorso") or LocalPlayer.Character:FindFirstChild("Torso")
            if LowerTorso and LowerTorso:FindFirstChild("RootJoint") then
                LowerTorso.RootJoint.Transform = CFrame.new()
            end
        end
    end

    if getgenv().ThirdPersonEnabled then
        local char = LocalPlayer.Character
        local hum = char and char:FindFirstChildOfClass("Humanoid")
        if hum then
            hum.CameraOffset = Vector3.new(1.5, 2, 0)
            LocalPlayer.CameraMinZoomDistance = getgenv().ThirdPersonDistance
            LocalPlayer.CameraMaxZoomDistance = getgenv().ThirdPersonDistance
            if Camera.CameraType ~= Enum.CameraType.Custom then
                Camera.CameraType = Enum.CameraType.Custom
            end
        end
    else
        local char = LocalPlayer.Character
        local hum = char and char:FindFirstChildOfClass("Humanoid")
        if hum and hum.CameraOffset ~= Vector3.new(0, 0, 0) then
            ResetCamera()
        end
    end

    local blurEffect = Lighting:FindFirstChild("hooksenseMotionBlur")
    if getgenv().MotionBlurEnabled then
        if not blurEffect then
            blurEffect = Instance.new("BlurEffect")
            blurEffect.Name = "hooksenseMotionBlur"
            blurEffect.Parent = Lighting
        end
        local currentLookVector = Camera.CFrame.LookVector
        local angleDifference = math.acos(math.clamp(currentLookVector:Dot(LastCameraRotation), -1, 1))
        local blurTarget = math.clamp(angleDifference * 45 * getgenv().MotionBlurIntensity, 0, 56)
        
        blurEffect.Size = blurEffect.Size + (blurTarget - blurEffect.Size) * 0.25
        LastCameraRotation = currentLookVector
    else
        if blurEffect then blurEffect:Destroy() end
    end

    for player, v in pairs(ESP_Storage) do
        local char = player.Character
        local head = char and char:FindFirstChild("Head")
        local hrp = char and char:FindFirstChild("HumanoidRootPart")
        local humanoid = char and char:FindFirstChildOfClass("Humanoid")
        
        if getgenv().ESPEnabled and char and head and hrp and humanoid and humanoid.Health > 0 then
            if getgenv().TeamCheckEnabled and player.Team == LocalPlayer.Team then
                local highlight = char:FindFirstChild("hooksenseHighlight")
                if highlight then highlight.Enabled = false end
                v.BillboardGui.Enabled = false
                continue
            end
            local highlight = char:FindFirstChild("hooksenseHighlight")
            if getgenv().ESPHighlights then
                if not highlight then
                    highlight = Instance.new("Highlight")
                    highlight.Name = "hooksenseHighlight"
                    highlight.Parent = char
                end
                highlight.FillColor = getgenv().ColorBox
                highlight.FillTransparency = 0.5
                highlight.OutlineColor = Color3.fromRGB(0, 0, 0)
                highlight.OutlineTransparency = 0
                highlight.Enabled = true
            else
                if highlight then highlight.Enabled = false end
            end

            if v.BillboardGui.Adornee ~= head then v.BillboardGui.Adornee = head end
            local _, OnScreen = Camera:WorldToViewportPoint(head.Position)
            if OnScreen then
                v.BillboardGui.Enabled = true
                local Distance = (Camera.CFrame.Position - hrp.Position).Magnitude
                v.NameTag.Text = player.Name .. " [" .. math.floor(Distance) .. "m]"
                v.NameTag.TextColor3 = getgenv().ColorName
                v.NameTag.Visible = getgenv().ESPName
                if getgenv().ESPHealth then
                    local currentHealth = math.floor(humanoid.Health)
                    local HealthPercentage = currentHealth / humanoid.MaxHealth
                    local healthColor = HealthPercentage > 0.6 and Color3.fromRGB(0, 255, 120) or (HealthPercentage > 0.3 and Color3.fromRGB(255, 215, 0) or Color3.fromRGB(255, 50, 50))
                    v.HealthTag.Text = "HP: " .. currentHealth
                    v.HealthTag.TextColor3 = healthColor
                    v.HealthTag.Visible = true
                else
                    v.HealthTag.Visible = false
                end
                continue
            end
        else
            local highlight = char and char:FindFirstChild("hooksenseHighlight")
            if highlight then highlight.Enabled = false end
        end
        v.BillboardGui.Enabled = false
    end
end)

task.spawn(function()
    while true do
        task.wait()
        if getgenv().BhopEnabled and LocalPlayer.Character then
            local Humanoid = LocalPlayer.Character:FindFirstChildOfClass("Humanoid")
            local Root = LocalPlayer.Character:FindFirstChild("HumanoidRootPart")
            if Humanoid and Root then
                local MoveDirection = Humanoid.MoveDirection
                if MoveDirection.Magnitude > 0 then
                    if Humanoid.FloorMaterial ~= Enum.Material.Air then
                        Humanoid:ChangeState(Enum.HumanoidStateType.Jumping)
                    end
                    Root.Velocity = Vector3.new(MoveDirection.X * (Humanoid.WalkSpeed * getgenv().BhopSpeedMultiplier), Root.Velocity.Y, MoveDirection.Z * (Humanoid.WalkSpeed * getgenv().BhopSpeedMultiplier))
                end
            end
        end
    end
end)

-- ============================================================================
-- [7] Silent Aim Hook Metamethod (รันแยกส่วนกับระบบ Anti-Remote)
-- ============================================================================
local OldNamecall
OldNamecall = hookmetamethod(game, "__namecall", newcclosure(function(Self, ...)
    if checkcaller() then return OldNamecall(Self, ...) end
    local Args = { ... }
    local Method = getnamecallmethod()
    local SelfClass = ""
    pcall(function()
        if Self and typeof(Self) == "Instance" then SelfClass = Self.ClassName end
    end)

    if getgenv().SilentAimEnabled and CurrentAimTargetPosition then
        if (Method == "ScreenPointToRay" or Method == "ViewportPointToRay") and SelfClass == "Camera" then
            return Ray.new(Camera.CFrame.Position, (CurrentAimTargetPosition - Camera.CFrame.Position).Unit)
        end
        if Method == "Raycast" and SelfClass == "Workspace" then
            if getgenv().BulletTPEnabled then
                Args[1] = CurrentAimTargetPosition - (Args[2].Unit * 1)
                Args[2] = Args[2].Unit * 5
            else
                Args[2] = (CurrentAimTargetPosition - Args[1]).Unit * Args[2].Magnitude
            end
            return OldNamecall(Self, table.unpack(Args))
        end
        if (Method == "FindPartOnRay" or Method == "FindPartOnRayWithIgnoreList" or Method == "FindPartOnRayWithWhitelist") and SelfClass == "Workspace" then
            local CurrentRay = Args[1]
            if CurrentRay and typeof(CurrentRay) == "Ray" then
                if getgenv().BulletTPEnabled then
                    local NewOrigin = CurrentAimTargetPosition - (CurrentRay.Direction.Unit * 1)
                    Args[1] = Ray.new(NewOrigin, CurrentRay.Direction.Unit * 5)
                else
                    Args[1] = Ray.new(CurrentRay.Origin, (CurrentAimTargetPosition - CurrentRay.Origin).Unit * CurrentRay.Direction.Magnitude)
                end
                return OldNamecall(Self, table.unpack(Args))
            end
        end
    end
    return OldNamecall(Self, ...)
end))

local Tabs = {
    Main = Window:AddTab("Main"),
    Aimbot = Window:AddTab("Aimbot"),
    HitEffects = Window:AddTab("Hits"),
    ESP = Window:AddTab("Esp"),
    Movement = Window:AddTab("Character"),
    World = Window:AddTab("World"),
    Addons = Window:AddTab("Misc"),
    ['UI'] = Window:AddTab("UI setting")
}

local Options = getgenv().Options
local Toggles = getgenv().Toggles

-- [Aimbot Tab Components]
local MobileAimbotBox = Tabs.Aimbot:AddLeftGroupbox("Aimbot")
local MobileAimbotSettings = Tabs.Aimbot:AddRightGroupbox("Aimbot Options")

MobileAimbotBox:AddToggle("MobileAimbotToggle", { Text = "Enable Aimbot", Default = false })
    :AddKeyPicker("MobileAimbotKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Mobile Aimbot Bind" })

Toggles.MobileAimbotToggle:OnChanged(function()
    getgenv().MobileAimbotEnabled = Toggles.MobileAimbotToggle.Value
end)

MobileAimbotBox:AddSlider("AimbotSmoothSlider", { Text = "Aimbot Smoothness", Default = 0.1, Min = 0.01, Max = 1, Rounding = 2 })
Options.AimbotSmoothSlider:OnChanged(function()
    getgenv().AimbotSmoothness = Options.AimbotSmoothSlider.Value
end)

MobileAimbotBox:AddSlider("JumpSmoothSlider", { Text = "Jump Smooth", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.JumpSmoothSlider:OnChanged(function()
    getgenv().JumpSmooth = Options.JumpSmoothSlider.Value
end)

MobileAimbotBox:AddSlider("SmoothXSlider", { Text = "Smooth X", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.SmoothXSlider:OnChanged(function()
    getgenv().SmoothX = Options.SmoothXSlider.Value
end)

MobileAimbotBox:AddSlider("SmoothZSlider", { Text = "Smooth Z", Default = 1, Min = 1, Max = 100, Rounding = 0, Suffix = "%" })
Options.SmoothZSlider:OnChanged(function()
    getgenv().SmoothZ = Options.SmoothZSlider.Value
end)

MobileAimbotBox:AddToggle("AutoPredictionToggle", { Text = "Enable Auto Prediction", Default = false })
Toggles.AutoPredictionToggle:OnChanged(function()
    getgenv().AutoPredictionEnabled = Toggles.AutoPredictionToggle.Value
end)

MobileAimbotBox:AddSlider("PredictionSlider", { Text = "Prediction Multiplier", Default = 0.1, Min = 0.0, Max = 5.0, Rounding = 2 })
Options.PredictionSlider:OnChanged(function()
    getgenv().PredictionValue = Options.PredictionSlider.Value
end)

MobileAimbotSettings:AddDropdown("MobileTargetPartDropdown", { Text = "Aimbot Target Part", Values = {"Head", "HumanoidRootPart"}, Default = 1, Multi = false })
Options.MobileTargetPartDropdown:OnChanged(function()
    getgenv().AimbotTargetPart = Options.MobileTargetPartDropdown.Value
end)

-- [Main Tab Components]
local LeftGroupBox = Tabs.Main:AddLeftGroupbox("Silent Aim")
local PermLockGroupBox = Tabs.Main:AddLeftGroupbox("Permanent Lock Settings")
local TargetGroupBox = Tabs.Main:AddLeftGroupbox("Targeting Options")
local FOVGroupBox = Tabs.Main:AddRightGroupbox("FOV Settings")
local FOVFillGroupBox = Tabs.Main:AddRightGroupbox("FOV Dynamic Gradient Fill")
local TracerGroupBox = Tabs.Main:AddRightGroupbox("Tracer Line Settings")

LeftGroupBox:AddToggle("SilentAimToggle", { Text = "Enable Silent Aim", Default = false })
    :AddKeyPicker("SilentAimKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Silent Aim Bind" })

Toggles.SilentAimToggle:OnChanged(function()
    getgenv().SilentAimEnabled = Toggles.SilentAimToggle.Value
end)

LeftGroupBox:AddToggle("ResolverToggle", { Text = "Enable Resolver", Default = false })
Toggles.ResolverToggle:OnChanged(function()
    getgenv().ResolverEnabled = Toggles.ResolverToggle.Value
end)

LeftGroupBox:AddToggle("LookAtToggle", { Text = "Enable Look at Target", Default = false })
    :AddKeyPicker("LookAtKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Look At Bind" })

Toggles.LookAtToggle:OnChanged(function()
    getgenv().LookAtEnabled = Toggles.LookAtToggle.Value
end)

LeftGroupBox:AddToggle("BulletTPToggle", { Text = "Enable Bullet TP", Default = false })
    :AddKeyPicker("BulletTPKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Bullet TP Bind" })

Toggles.BulletTPToggle:OnChanged(function()
    getgenv().BulletTPEnabled = Toggles.BulletTPToggle.Value
end)

LeftGroupBox:AddToggle("WallCheckToggle", { Text = "Enable Wall Check", Default = false })
Toggles.WallCheckToggle:OnChanged(function()
    getgenv().WallCheckEnabled = Toggles.WallCheckToggle.Value
end)

LeftGroupBox:AddToggle("TeamCheckToggle", { Text = "Enable Team Check", Default = false })
Toggles.TeamCheckToggle:OnChanged(function()
    getgenv().TeamCheckEnabled = Toggles.TeamCheckToggle.Value
end)

PermLockGroupBox:AddToggle("PermLockToggle", { Text = "Enable Perm Lock-On", Default = false })
    :AddKeyPicker("PermLockKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Perm Lock Bind" })

Toggles.PermLockToggle:OnChanged(function()
    getgenv().PermLockEnabled = Toggles.PermLockToggle.Value
end)

PermLockGroupBox:AddDropdown("PermTargetDropdown", { Text = "Targets Queue List", Values = {"No Targets Added"}, Default = 1, Multi = false })

local function RefreshDropdownValues()
    if #getgenv().PermTargetList == 0 then
        Options.PermTargetDropdown:SetValues({"No Targets Added"})
        Options.PermTargetDropdown:SetValue(1)
    else
        for i = #getgenv().PermTargetList, 1, -1 do
            if not Players:FindFirstChild(getgenv().PermTargetList[i]) then
                table.remove(getgenv().PermTargetList, i)
            end
        end
        if #getgenv().PermTargetList == 0 then
            Options.PermTargetDropdown:SetValues({"No Targets Added"})
            Options.PermTargetDropdown:SetValue(1)
        else
            Options.PermTargetDropdown:SetValues(getgenv().PermTargetList)
            Options.PermTargetDropdown:SetValue(getgenv().PermTargetList[1])
        end
    end
end

Players.PlayerRemoving:Connect(function(player)
    task.wait(0.1)
    RefreshDropdownValues()
end)
Players.PlayerAdded:Connect(function(player)
    task.wait(0.1)
    RefreshDropdownValues()
end)

PermLockGroupBox:AddButton({Text = "Clear All Targets", Func = function()
    getgenv().PermTargetList = {}
    RefreshDropdownValues()
    Library:Notify("Permanent Target List Cleared!")
end})

PermLockGroupBox:AddInput("PermTargetInput", { Placeholder = "Enter Display or Username...", Text = "", Numeric = false, Finished = false, })
PermLockGroupBox:AddButton({Text = "Target Player", Func = function()
    local enteredText = Options.PermTargetInput.Value
    if enteredText and enteredText ~= "" then
        enteredText = string.gsub(enteredText, "%s+", "")
        local matchFound = nil
        for _, p in ipairs(Players:GetPlayers()) do
            local nameMatch = string.find(string.lower(p.Name), string.lower(enteredText))
            local dispMatch = string.find(string.lower(p.DisplayName), string.lower(enteredText))
            if nameMatch or dispMatch then
                matchFound = p.Name
                break
            end
        end
        if matchFound then
            if not table.find(getgenv().PermTargetList, matchFound) then
                table.insert(getgenv().PermTargetList, matchFound)
                RefreshDropdownValues()
                Options.PermTargetDropdown:SetValue(matchFound)
                Library:Notify("Successfully Targeted: " .. matchFound)
            else
                Library:Notify("Player already exists in list!")
            end
        else
            Library:Notify("No matching player found on this server!")
        end
        Options.PermTargetInput:SetValue("")
    else
        Library:Notify("Please enter a valid player name.")
    end
end})

-- [เพิ่มตัวเลือก Closet ลงใน Dropdown เรียบร้อย]
TargetGroupBox:AddDropdown("TargetPartDropdown", { Text = "Target Lock Part", Values = {"Head", "HumanoidRootPart", "Root to Head", "Closet"}, Default = 1, Multi = false })
Options.TargetPartDropdown:OnChanged(function()
    getgenv().TargetPartMode = Options.TargetPartDropdown.Value
end)

TargetGroupBox:AddSlider("TransitionSpeedSlider", { Text = "Root Transfer Speed (Root to Head)", Default = 5, Min = 1, Max = 30, Rounding = 1 })
Options.TransitionSpeedSlider:OnChanged(function()
    getgenv().TransitionSpeed = Options.TransitionSpeedSlider.Value
end)

TargetGroupBox:AddSlider("MaxDistanceSlider", { Text = "Max Lock Distance (Studs)", Default = 10000, Min = 1, Max = 99999999, Rounding = 0 })
Options.MaxDistanceSlider:OnChanged(function()
    getgenv().MaxTargetDistance = Options.MaxDistanceSlider.Value
end)

FOVGroupBox:AddToggle("FOVVisibleToggle", { Text = "Show FOV Circle", Default = true })
Toggles.FOVVisibleToggle:OnChanged(function()
    getgenv().FOVVisible = Toggles.FOVVisibleToggle.Value
end)

FOVGroupBox:AddSlider("FOVSlider", { Text = "FOV Size Radius", Default = 100, Min = 40, Max = 800, Rounding = 0 })
Options.FOVSlider:OnChanged(function()
    getgenv().FOVSize = Options.FOVSlider.Value
end)

FOVGroupBox:AddLabel("FOV Line Color"):AddColorPicker("FOVCircleColorPicker", { Default = Color3.fromRGB(255, 255, 255) })
Options.FOVCircleColorPicker:OnChanged(function()
    getgenv().FOVCircleColor = Options.FOVCircleColorPicker.Value
end)

FOVGroupBox:AddLabel("FOV Outline Color"):AddColorPicker("FOVCircleOutlineColorPicker", { Default = Color3.fromRGB(0, 0, 0) })
Options.FOVCircleOutlineColorPicker:OnChanged(function()
    getgenv().FOVCircleOutlineColor = Options.FOVCircleOutlineColorPicker.Value
end)

FOVFillGroupBox:AddToggle("FOVFillToggle", { Text = "Enable FOV Fill", Default = false })
Toggles.FOVFillToggle:OnChanged(function()
    getgenv().FOVFillEnabled = Toggles.FOVFillToggle.Value
end)

FOVFillGroupBox:AddSlider("FOVFillTransparencySlider", { Text = "FOV Fill Opacity", Default = 0.2, Min = 0, Max = 1, Rounding = 2 })
Options.FOVFillTransparencySlider:OnChanged(function()
    getgenv().FOVFillTransparency = Options.FOVFillTransparencySlider.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 1 (Top)"):AddColorPicker("FOVFillColor1Picker", { Default = Color3.fromRGB(255, 0, 0) })
Options.FOVFillColor1Picker:OnChanged(function()
    getgenv().FOVFillColor1 = Options.FOVFillColor1Picker.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 2 (Mid)"):AddColorPicker("FOVFillColor2Picker", { Default = Color3.fromRGB(0, 255, 0) })
Options.FOVFillColor2Picker:OnChanged(function()
    getgenv().FOVFillColor2 = Options.FOVFillColor2Picker.Value
end)

FOVFillGroupBox:AddLabel("Fill Color 3 (Bottom)"):AddColorPicker("FOVFillColor3Picker", { Default = Color3.fromRGB(0, 0, 255) })
Options.FOVFillColor3Picker:OnChanged(function()
    getgenv().FOVFillColor3 = Options.FOVFillColor3Picker.Value
end)

FOVFillGroupBox:AddToggle("FOVFillRotateToggle", { Text = "Rotate FOV Gradient", Default = false })
Toggles.FOVFillRotateToggle:OnChanged(function()
    getgenv().FOVFillRotateEnabled = Toggles.FOVFillRotateToggle.Value
end)

FOVFillGroupBox:AddSlider("FOVFillRotateSpeedSlider", { Text = "Gradient Rotation Speed", Default = 1, Min = 1, Max = 10, Rounding = 1 })
Options.FOVFillRotateSpeedSlider:OnChanged(function()
    getgenv().FOVFillRotateSpeed = Options.FOVFillRotateSpeedSlider.Value
end)

TracerGroupBox:AddToggle("TracerVisibleToggle", { Text = "Enable Tracer Line", Default = true })
Toggles.TracerVisibleToggle:OnChanged(function()
    getgenv().TracerEnabled = Toggles.TracerVisibleToggle.Value
end)

TracerGroupBox:AddSlider("TracerThicknessSlider", { Text = "Tracer Line Thickness", Default = 1.0, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.TracerThicknessSlider:OnChanged(function()
    getgenv().TracerThickness = Options.TracerThicknessSlider.Value
end)

TracerGroupBox:AddSlider("TracerOutlineThicknessSlider", { Text = "Tracer Outline Thickness", Default = 3.0, Min = 1.0, Max = 8.0, Rounding = 1 })
Options.TracerOutlineThicknessSlider:OnChanged(function()
    getgenv().TracerOutlineThickness = Options.TracerOutlineThicknessSlider.Value
end)

TracerGroupBox:AddLabel("Tracer Main Color"):AddColorPicker("TracerLineColorPicker", { Default = Color3.fromRGB(255, 0, 0) })
Options.TracerLineColorPicker:OnChanged(function()
    getgenv().TracerLineColor = Options.TracerLineColorPicker.Value
end)

TracerGroupBox:AddLabel("Tracer Outline Color"):AddColorPicker("TracerLineOutlineColorPicker", { Default = Color3.fromRGB(0, 0, 0) })
Options.TracerLineOutlineColorPicker:OnChanged(function()
    getgenv().TracerLineOutlineColor = Options.TracerLineOutlineColorPicker.Value
end)

-- [HitEffects Tab Components]
local SoundLeftBox = Tabs.HitEffects:AddLeftGroupbox("Hit Sound")
local OverlayLeftBox = Tabs.HitEffects:AddLeftGroupbox("Hit Overlay") 
local NotifyRightBox = Tabs.HitEffects:AddRightGroupbox("Hit Notification Custom System")

SoundLeftBox:AddDropdown("HitSoundDropdown", { Text = "Target Hit Sound", Values = {"None", "Spark", "Neverlose", "Rust", "Fatality", "Fatality 2", "Minecraft xp", "Minecraft", "Crack", "Skeet"}, Default = 1, Multi = false })
Options.HitSoundDropdown:OnChanged(function()
    getgenv().HitSoundMode = Options.HitSoundDropdown.Value
end)

SoundLeftBox:AddSlider("HitSoundVolumeSlider", { Text = "Hit Sound Volume Level", Default = 2.0, Min = 0.0, Max = 5.0, Rounding = 1 })
Options.HitSoundVolumeSlider:OnChanged(function()
    getgenv().HitSoundVolume = Options.HitSoundVolumeSlider.Value
end)

OverlayLeftBox:AddToggle("HitOverlayToggle", { Text = "Enable Hit Overlay", Default = false })
Toggles.HitOverlayToggle:OnChanged(function()
    getgenv().HitOverlayEnabled = Toggles.HitOverlayToggle.Value
end)

OverlayLeftBox:AddLabel("Overlay Border Color"):AddColorPicker("HitOverlayColorPicker", { Default = Color3.fromRGB(255, 0, 0) })
Options.HitOverlayColorPicker:OnChanged(function()
    getgenv().HitOverlayColor = Options.HitOverlayColorPicker.Value
end)

NotifyRightBox:AddToggle("HitNotifyToggle", { Text = "Enable Hit Notification", Default = false })
Toggles.HitNotifyToggle:OnChanged(function()
    getgenv().HitNotifyEnabled = Toggles.HitNotifyToggle.Value
end)

NotifyRightBox:AddSlider("HitNotifyDurationSlider", { Text = "Notification Duration (s)", Default = 2.5, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.HitNotifyDurationSlider:OnChanged(function()
    getgenv().HitNotifyDuration = Options.HitNotifyDurationSlider.Value
end)

NotifyRightBox:AddSlider("HitNotifyTransparencySlider", { Text = "Notification Opacity/Transparency", Default = 0, Min = 0, Max = 1, Rounding = 2 })
Options.HitNotifyTransparencySlider:OnChanged(function()
    getgenv().HitNotifyTransparency = Options.HitNotifyTransparencySlider.Value
end)

NotifyRightBox:AddSlider("HitNotifyPosXSlider", { Text = "Position X Offset (%)", Default = 50, Min = 1, Max = 100, Rounding = 0 })
Options.HitNotifyPosXSlider:OnChanged(function()
    getgenv().HitNotifyPosX = Options.HitNotifyPosXSlider.Value
    CenterNotifyContainer.Position = UDim2.new(getgenv().HitNotifyPosX / 100, 0, getgenv().HitNotifyPosY / 100, 0)
end)

NotifyRightBox:AddSlider("HitNotifyPosYSlider", { Text = "Position Y Offset (%)", Default = 65, Min = 1, Max = 100, Rounding = 0 })
Options.HitNotifyPosYSlider:OnChanged(function()
    getgenv().HitNotifyPosY = Options.HitNotifyPosYSlider.Value
    CenterNotifyContainer.Position = UDim2.new(getgenv().HitNotifyPosX / 100, 0, getgenv().HitNotifyPosY / 100, 0)
end)

NotifyRightBox:AddDropdown("HitNotifyFontDropdown", { Text = "Hit Notify Custom Font", Values = RobloxFontsList, Default = table.find(RobloxFontsList, "Cartoon") or 1, Multi = false })
Options.HitNotifyFontDropdown:OnChanged(function()
    local SelectedFont = Enum.Font[Options.HitNotifyFontDropdown.Value]
    if SelectedFont then
        getgenv().HitNotifyFont = SelectedFont
    end
end)

NotifyRightBox:AddInput("CustomHitNotifyInput", { Placeholder = "Format: {name} | {part} | {dmg} | {weapon}", Text = "Hit {name} in the {part} for {dmg} dmg with {weapon}", Numeric = false, Finished = true })
Options.CustomHitNotifyInput:OnChanged(function()
    if Options.CustomHitNotifyInput.Value and Options.CustomHitNotifyInput.Value ~= "" then
        getgenv().HitNotifyTemplate = Options.CustomHitNotifyInput.Value
    end
end)

-- [ESP Tab Components]
local EspLeftBox = Tabs.ESP:AddLeftGroupbox("Visuals Control")
local EspRightBox = Tabs.ESP:AddRightGroupbox("Color Customization")

EspLeftBox:AddToggle("MasterESPToggle", { Text = "Enable ESP", Default = false })
    :AddKeyPicker("MasterESPKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Master ESP Bind" })

Toggles.MasterESPToggle:OnChanged(function()
    getgenv().ESPEnabled = Toggles.MasterESPToggle.Value
end)

EspLeftBox:AddToggle("NameESPToggle", { Text = "Player Name ESP", Default = false })
Toggles.NameESPToggle:OnChanged(function()
    getgenv().ESPName = Toggles.NameESPToggle.Value
end)

EspLeftBox:AddToggle("ChamsESPToggle", { Text = "Chams / Highlights ESP", Default = false })
Toggles.ChamsESPToggle:OnChanged(function()
    getgenv().ESPHighlights = Toggles.ChamsESPToggle.Value
end)

EspLeftBox:AddToggle("HealthESPToggle", { Text = "Health Text ESP", Default = false })
Toggles.HealthESPToggle:OnChanged(function()
    getgenv().ESPHealth = Toggles.HealthESPToggle.Value
end)

EspRightBox:AddLabel("Highlight Glow Color"):AddColorPicker("GlowColorPicker", { Default = Color3.fromRGB(0, 255, 255) })
Options.GlowColorPicker:OnChanged(function()
    getgenv().ColorBox = Options.GlowColorPicker.Value
end)

EspRightBox:AddLabel("Name Text Color"):AddColorPicker("NameColorPicker", { Default = Color3.fromRGB(255, 255, 255) })
Options.NameColorPicker:OnChanged(function()
    getgenv().ColorName = Options.NameColorPicker.Value
end)

-- [Movement Tab Components]
local MoveLeftBox = Tabs.Movement:AddLeftGroupbox("Anti Aim")
local MoveRightBox = Tabs.Movement:AddRightGroupbox("Movement & Camera")

MoveLeftBox:AddToggle("AntiAimToggle", { Text = "Enable Anti Aim", Default = false })
    :AddKeyPicker("AntiAimKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Anti Aim Bind" })

Toggles.AntiAimToggle:OnChanged(function()
    getgenv().AntiAimEnabled = Toggles.AntiAimToggle.Value
end)

MoveLeftBox:AddDropdown("AntiAimModeDropdown", { Text = "Anti Aim Stance Type", Values = {"Spin", "Jitter"}, Default = 1, Multi = false })
Options.AntiAimModeDropdown:OnChanged(function()
    getgenv().AntiAimMode = Options.AntiAimModeDropdown.Value
end)

MoveLeftBox:AddDropdown("JitterSettingDropdown", { Text = "Jitter Core Settings", Values = {"Multi", "5x always", "3x always", "2x always", "random"}, Default = 1, Multi = false })
Options.JitterSettingDropdown:OnChanged(function()
    getgenv().JitterMode = Options.JitterSettingDropdown.Value
end)

MoveLeftBox:AddSlider("SpinSpeedSlider", { Text = "Rotation Spin Speed", Default = 15, Min = 5, Max = 50, Rounding = 0 })
Options.SpinSpeedSlider:OnChanged(function()
    getgenv().AntiAimSpeed = Options.SpinSpeedSlider.Value
end)

MoveRightBox:AddToggle("ThirdPersonToggle", { Text = "Enable Third Person View", Default = false })
    :AddKeyPicker("ThirdPersonKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Third Person Bind" })

Toggles.ThirdPersonToggle:OnChanged(function()
    getgenv().ThirdPersonEnabled = Toggles.ThirdPersonToggle.Value
end)

MoveRightBox:AddSlider("ThirdPersonDistanceSlider", { Text = "Third Person Distance Modifier", Default = 12, Min = 5, Max = 30, Rounding = 0 })
Options.ThirdPersonDistanceSlider:OnChanged(function()
    getgenv().ThirdPersonDistance = Options.ThirdPersonDistanceSlider.Value
end)

MoveRightBox:AddToggle("BhopToggle", { Text = "Enable Auto Bunny Hop", Default = false })
    :AddKeyPicker("BhopKeybind", { Default = "None", SyncToggleState = true, Mode = "Toggle", Text = "Bhop Bind" })

Toggles.BhopToggle:OnChanged(function()
    getgenv().BhopEnabled = Toggles.BhopToggle.Value
end)

MoveRightBox:AddSlider("BhopMultiplierSlider", { Text = "Bhop Velocity Speed Multiplier", Default = 1.5, Min = 1, Max = 5, Rounding = 1 })
Options.BhopMultiplierSlider:OnChanged(function()
    getgenv().BhopSpeedMultiplier = Options.BhopMultiplierSlider.Value
end)

-- [World Tab Components]
local LightingColorsGroup = Tabs.World:AddLeftGroupbox("Lighting Colors & Time")
local WorldSkyboxBox = Tabs.World:AddLeftGroupbox("Custom Skybox System")
local WorldFogBox = Tabs.World:AddLeftGroupbox("World Fog Customization")
local WorldAtmosphereBox = Tabs.World:AddLeftGroupbox("World Atmosphere Customization")
local CameraDisplayBox = Tabs.World:AddRightGroupbox("Camera & Display Settings")

LightingColorsGroup:AddSlider("ClockTimeSlider", { Text = "Game Clock Time", Default = Lighting.ClockTime, Min = 0, Max = 24, Rounding = 1 })
Options.ClockTimeSlider:OnChanged(function()
    Lighting.ClockTime = Options.ClockTimeSlider.Value
end)

LightingColorsGroup:AddLabel("Ambient Color"):AddColorPicker("AmbientColorPicker", { Default = Lighting.Ambient })
Options.AmbientColorPicker:OnChanged(function()
    Lighting.Ambient = Options.AmbientColorPicker.Value
end)

LightingColorsGroup:AddLabel("Outdoor Ambient Color"):AddColorPicker("OutdoorAmbientColorPicker", { Default = Lighting.OutdoorAmbient })
Options.OutdoorAmbientColorPicker:OnChanged(function()
    Lighting.OutdoorAmbient = Options.OutdoorAmbientColorPicker.Value
end)

LightingColorsGroup:AddLabel("ColorShift Top Color"):AddColorPicker("ColorShiftTopColorPicker", { Default = Lighting.ColorShift_Top })
Options.ColorShiftTopColorPicker:OnChanged(function()
    Lighting.ColorShift_Top = Options.ColorShiftTopColorPicker.Value
end)

LightingColorsGroup:AddLabel("ColorShift Bottom Color"):AddColorPicker("ColorShiftBottomColorPicker", { Default = Lighting.ColorShift_Bottom })
Options.ColorShiftBottomColorPicker:OnChanged(function()
    Lighting.ColorShift_Bottom = Options.ColorShiftBottomColorPicker.Value
end)

WorldSkyboxBox:AddToggle("SkyboxToggle", { Text = "Enable Custom Skybox", Default = false })
Toggles.SkyboxToggle:OnChanged(function()
    getgenv().SkyboxEnabled = Toggles.SkyboxToggle.Value
    UpdateSkybox()
end)

WorldSkyboxBox:AddDropdown("SkyboxDropdown", { Text = "Select Skybox", Values = {"Minecraft", "Minecraft 2", "Skyblox 1", "Skyblox 2", "Skyblox 3", "Skyblox 4", "Skyblox 5"}, Default = 1, Multi = false })
Options.SkyboxDropdown:OnChanged(function()
    getgenv().SelectedSkybox = Options.SkyboxDropdown.Value
    UpdateSkybox()
end)

WorldFogBox:AddLabel("Fog Color"):AddColorPicker("FogColorPicker", { Default = Lighting.FogColor })
Options.FogColorPicker:OnChanged(function()
    Lighting.FogColor = Options.FogColorPicker.Value
end)

WorldFogBox:AddSlider("FogStartSlider", { Text = "Fog Start Distance", Default = Lighting.FogStart, Min = 0, Max = 5000, Rounding = 0 })
Options.FogStartSlider:OnChanged(function()
    Lighting.FogStart = Options.FogStartSlider.Value
end)

WorldFogBox:AddSlider("FogEndSlider", { Text = "Fog End Distance", Default = Lighting.FogEnd, Min = 0, Max = 10000, Rounding = 0 })
Options.FogEndSlider:OnChanged(function()
    Lighting.FogEnd = Options.FogEndSlider.Value
end)

WorldAtmosphereBox:AddToggle("AtmosphereToggle", { Text = "Enable Atmosphere", Default = false })
Toggles.AtmosphereToggle:OnChanged(function()
    getgenv().AtmosphereEnabled = Toggles.AtmosphereToggle.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddLabel("Tint Color"):AddColorPicker("AtmosColorPicker", { Default = getgenv().AtmosphereColor })
Options.AtmosColorPicker:OnChanged(function()
    getgenv().AtmosphereColor = Options.AtmosColorPicker.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddLabel("Decay Color"):AddColorPicker("AtmosDecayPicker", { Default = getgenv().AtmosphereDecay })
Options.AtmosDecayPicker:OnChanged(function()
    getgenv().AtmosphereDecay = Options.AtmosDecayPicker.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosGlareSlider", { Text = "Glare Intensity", Default = getgenv().AtmosphereGlare, Min = 0.1, Max = 10, Rounding = 1 })
Options.AtmosGlareSlider:OnChanged(function()
    getgenv().AtmosphereGlare = Options.AtmosGlareSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosHazeSlider", { Text = "Haze Density", Default = getgenv().AtmosphereHaze, Min = 0.1, Max = 10, Rounding = 1 })
Options.AtmosHazeSlider:OnChanged(function()
    getgenv().AtmosphereHaze = Options.AtmosHazeSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosOffsetSlider", { Text = "Horizon Offset", Default = getgenv().AtmosphereOffset, Min = 0.01, Max = 1, Rounding = 2 })
Options.AtmosOffsetSlider:OnChanged(function()
    getgenv().AtmosphereOffset = Options.AtmosOffsetSlider.Value
    UpdateAtmosphere()
end)

WorldAtmosphereBox:AddSlider("AtmosDensitySlider", { Text = "Atmosphere Density", Default = getgenv().AtmosphereDensity, Min = 0.01, Max = 1, Rounding = 2 })
Options.AtmosDensitySlider:OnChanged(function()
    getgenv().AtmosphereDensity = Options.AtmosDensitySlider.Value
    UpdateAtmosphere()
end)

CameraDisplayBox:AddSlider("CustomFovSlider", { Text = "Custom FOV", Default = 70, Min = 70, Max = 120, Rounding = 0 })
Options.CustomFovSlider:OnChanged(function()
    getgenv().CustomFOVValue = Options.CustomFovSlider.Value
    Camera.FieldOfView = getgenv().CustomFOVValue
end)

Camera:GetPropertyChangedSignal("FieldOfView"):Connect(function()
    if Camera.FieldOfView ~= getgenv().CustomFOVValue then
        Camera.FieldOfView = getgenv().CustomFOVValue
    end
end)

CameraDisplayBox:AddSlider("BlurSlider", { Text = "World Blur", Default = 0, Min = 0, Max = 5, Rounding = 1 })
Options.BlurSlider:OnChanged(function()
    local blurValue = Options.BlurSlider.Value
    local blurEffect = Lighting:FindFirstChild("hooksenseWorldBlur")
    if blurValue > 0 then
        if not blurEffect then
            blurEffect = Instance.new("BlurEffect")
            blurEffect.Name = "hooksenseWorldBlur"
            blurEffect.Parent = Lighting
        end
        blurEffect.Size = blurValue * 8
    else
        if blurEffect then blurEffect:Destroy() end
    end
end)

CameraDisplayBox:AddToggle("MotionBlurToggle", { Text = "Enable Motion Blur", Default = false })
Toggles.MotionBlurToggle:OnChanged(function()
    getgenv().MotionBlurEnabled = Toggles.MotionBlurToggle.Value
end)

CameraDisplayBox:AddSlider("MotionBlurIntensitySlider", { Text = "Motion Blur Intensity", Default = 1.5, Min = 0.5, Max = 5.0, Rounding = 1 })
Options.MotionBlurIntensitySlider:OnChanged(function()
    getgenv().MotionBlurIntensity = Options.MotionBlurIntensitySlider.Value
end)

CameraDisplayBox:AddSlider("FpsCapSlider", { Text = "FPS Cap Limit", Default = 60, Min = 60, Max = 999, Rounding = 0 })
Options.FpsCapSlider:OnChanged(function()
    if setfpscap then setfpscap(Options.FpsCapSlider.Value) end
end)

-- [Addons Tab Components]
local BlacklistPlayersGroup = Tabs.Addons:AddLeftGroupbox("loaders Scripts")
local TargetHudConfigGroup = Tabs.Addons:AddRightGroupbox("Target HUD Settings")

TargetHudConfigGroup:AddToggle("TargetHudMasterToggle", { Text = "Enable Target HUD", Default = false })
Toggles.TargetHudMasterToggle:OnChanged(function()
    getgenv().TargetHudToggle = Toggles.TargetHudMasterToggle.Value
end)

TargetHudConfigGroup:AddSlider("TargetHudPosXSlider", { Text = "Position X Offset", Default = 0, Min = -1000, Max = 1000, Rounding = 0 })
Options.TargetHudPosXSlider:OnChanged(function()
    getgenv().TargetHudPosX = Options.TargetHudPosXSlider.Value
end)

TargetHudConfigGroup:AddSlider("TargetHudPosYSlider", { Text = "Position Y Offset", Default = 0, Min = -1000, Max = 1000, Rounding = 0 })
Options.TargetHudPosYSlider:OnChanged(function()
    getgenv().TargetHudPosY = Options.TargetHudPosYSlider.Value
end)

TargetHudConfigGroup:AddLabel("Border Color 1"):AddColorPicker("HudBorderColor1Picker", { Default = Color3.fromRGB(0, 255, 100) })
Options.HudBorderColor1Picker:OnChanged(function()
    getgenv().TargetHudBorderColor1 = Options.HudBorderColor1Picker.Value
    BorderGradient.Color = ColorSequence.new({
        ColorSequenceKeypoint.new(0, getgenv().TargetHudBorderColor1),
        ColorSequenceKeypoint.new(1, getgenv().TargetHudBorderColor2)
    })
end)

TargetHudConfigGroup:AddLabel("Border Color 2"):AddColorPicker("HudBorderColor2Picker", { Default = Color3.fromRGB(0, 150, 0) })
Options.HudBorderColor2Picker:OnChanged(function()
    getgenv().TargetHudBorderColor2 = Options.HudBorderColor2Picker.Value
    BorderGradient.Color = ColorSequence.new({
        ColorSequenceKeypoint.new(0, getgenv().TargetHudBorderColor1),
        ColorSequenceKeypoint.new(1, getgenv().TargetHudBorderColor2)
    })
end)

TargetHudConfigGroup:AddLabel("Health Color: High (>60%)"):AddColorPicker("HudHealthHighPicker", { Default = Color3.fromRGB(0, 255, 100) })
Options.HudHealthHighPicker:OnChanged(function()
    getgenv().TargetHudHealthHigh = Options.HudHealthHighPicker.Value
end)

TargetHudConfigGroup:AddLabel("Health Color: Medium (30%-60%)"):AddColorPicker("HudHealthMidPicker", { Default = Color3.fromRGB(255, 200, 0) })
Options.HudHealthMidPicker:OnChanged(function() 
    getgenv().TargetHudHealthMid = Options.HudHealthMidPicker.Value
end)

TargetHudConfigGroup:AddLabel("Health Color: Low (<30%)"):AddColorPicker("HudHealthLowPicker", { Default = Color3.fromRGB(255, 50, 50) })
Options.HudHealthLowPicker:OnChanged(function()
    getgenv().TargetHudHealthLow = Options.HudHealthLowPicker.Value
end)

BlacklistPlayersGroup:AddButton({ Text = "walkspeed", Func = function()
    local success, err = pcall(function()
        loadstring(game:HttpGet('https://raw.githubusercontent.com/19mdSkibidi/19sMooze-Mobile-Rework/refs/heads/main/Mooze%20Mob'))()
    end)
    if success then
        Library:Notify("successfully!")
    else
        Library:Notify("Error loading script: " .. tostring(err))
    end
end })

BlacklistPlayersGroup:AddButton({ Text = "drawing esp", Func = function()
    local success, err = pcall(function()
        loadstring(game:HttpGet("https://raw.githubusercontent.com/xqmt/Drawing-Esp-/refs/heads/main/99"))()
    end)
    if success then
        Library:Notify("successfully!")
    else
        Library:Notify("Error loading script: " .. tostring(err))
    end
end })

-- [UI Tab Components & Complete End Statement]
local InterfaceGroup = Tabs['UI']:AddLeftGroupbox("Global Font Customization")
local MenuGroup = Tabs['UI']:AddLeftGroupbox("Menu Settings")
local AppearanceGroup = Tabs['UI']:AddRightGroupbox("UI Appearance Customization")

InterfaceGroup:AddDropdown("GlobalFontDropdown", { Text = "Select Script Font", Values = RobloxFontsList, Default = table.find(RobloxFontsList, "Cartoon") or 1, Multi = false })

ThemeManager:SetLibrary(Library)
SaveManager:SetLibrary(Library)
SaveManager:IgnoreThemeSettings()
SaveManager:SetIgnoreIndexes({ 'BackgroundColor', 'MainColor', 'AccentColor', 'OutlineColor', 'FontColor' })
ThemeManager:SetFolder("hooksense")
SaveManager:SetFolder("hooksense")
SaveManager:BuildConfigSection(Tabs['UI'])
ThemeManager:ApplyToTab(Tabs['UI'])
